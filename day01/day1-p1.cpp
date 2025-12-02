#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream file;
	std::string data;

	int value = 50;
	int counter = 0;

	file.open("input.txt");
	while(std::getline(file, data)) {
		int sign = data[0] == 'L' ? -1 : 1;
		int delta = sign * std::stoi(data.substr(1));

		value += delta;
		value %= 100;

		if (value < 0)
			value += 100;

		if (value == 0)
			counter++;
	}

	std::cout << counter << std::endl;

	return 0;
}
