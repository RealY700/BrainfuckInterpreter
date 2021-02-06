#include<iostream>
#include<vector>
#include<string>
#include<deque>

int commands(std::string code)
{
	std::deque<char> memory;
	std::vector<int> memory2;
	std::vector<int> negativeMem;
	int loopCount = 0;
	int8_t position = 0;
	std::string currentInput;
	memory.push_back(0);
	negativeMem.push_back(0);
	for (int i = 0; i < (int)code.length(); i++) {
		switch (code[i]) {
		case '>':
			position++;
			if (position >= memory.size()) {
				memory.push_back(0);
			}
			break;

		case '<':
			position--;
			if (position == -1) {
				memory.push_front(0);
				position++;
			}
			break;

		case ',':
			getline(std::cin, currentInput);
				memory[position] = (int)currentInput[0];
			break;

		case '.':
				std::cout << (char)memory[position];
			break;

		case '+':
				memory[position]++;
			break;

		case '-':
				memory[position]--;
			break;

		case '[':
				if (memory[position] == 0) {
					loopCount = 1;
					while (loopCount > 0) {
						i++;
						if (code[i] == '[') {
							loopCount++;
						} else if (code[i] == ']') {
							loopCount--;
						}
					}
				}
			break;

		case ']':
			if (memory[position] != 0) {
				loopCount = 1;
				while (loopCount > 0) {
					i--;
					if (code[i] == ']') {
						loopCount++;
					}
					else if (code[i] == '[') {
						loopCount--;
					}
				}
			}
			break;
		default:
			;
		}

	}


	return 0;
}

int main()
{
	std::string input;
	getline(std::cin, input);
	commands(input);
	return 0;
}