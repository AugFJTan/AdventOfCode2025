#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdint>

int main() {
	std::ifstream file;
	std::string line;

	uint64_t values[1000][4];
	char operations[1000];
	int row = 0;
	uint64_t total = 0;

	file.open("input.txt");
	while(std::getline(file, line)) {
		int col = 0;
		std::string data;
		std::istringstream ss(line);
		while(ss >> data) {
			if (row < 4)
				values[col][row] = std::stoi(data);
			else
				operations[col] = data[0];
			col++;
		}
		row++;
	}

	for (int i = 0; i < 1000; i++) {
		if (operations[i] == '+')
			total += values[i][0] + values[i][1] + values[i][2] + values[i][3];
		else
			total += values[i][0] * values[i][1] * values[i][2] * values[i][3];
	}

	std::cout << total << std::endl;

	return 0;
}