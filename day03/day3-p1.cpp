#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream file;
	std::string data;

	int total = 0;

	file.open("input.txt");
	while(std::getline(file, data)) {
		char buffer[data.length()];
		int highest = 0;

		for (int i = 0; i < data.length(); i++)
			buffer[i] = data[i] - '0';

		for (int i = 0; i < data.length() - 1; i++) {
			for (int j = i + 1; j < data.length(); j++) {
				int value = buffer[i] * 10 + buffer[j];
				if (value > highest)
					highest = value;
			}
		}

		total += highest;
	}

	std::cout << total << std::endl;

	return 0;
}
