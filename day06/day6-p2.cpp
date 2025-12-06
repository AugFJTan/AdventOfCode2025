#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdint>

int main() {
	std::ifstream file;
	std::string line;

	std::vector<std::string> data;
	uint64_t total = 0;

	file.open("input.txt");
	while(std::getline(file, line))
		data.push_back(line);

	int length = data[0].length();
	int i = length-1;

	while(i > 0) {
		std::vector<uint64_t> values;
		char operation;

		do {
			std::string number = "";
			for (int j = 0; j < 4; j++)
				number += data[j][i];
			values.push_back(std::stoi(number));
			operation = data[4][i];
			i--;
		} while(operation == ' ');
		i--;

		uint64_t result;
		if (operation == '+') {
			result = 0;
			for (uint64_t value : values)
				result += value;
		} else {
			result = 1;
			for (uint64_t value : values)
				result *= value;
		}
		total += result;
	}

	std::cout << total << std::endl;

	return 0;
}