#include <iostream>
#include <fstream>
#include <string>

#define ROWS 140
#define COLS 140

bool valid_pos(int r, int c) {
	return r >= 0 && r <= ROWS-1 && c >= 0 && c <= COLS-1;
}

int main() {
	std::ifstream file;
	std::string data;
	int row = 0;

	char map[ROWS][COLS];
	int total = 0;

	file.open("input.txt");
	while(std::getline(file, data)) {
		for (int i = 0; i < data.length(); i++)
			map[row][i] = data[i];
		row++;
	}

	for (int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++) {
			if (map[i][j] == '.')
				continue;

			int rolls = 0;
			for (int r = -1; r <= 1; r++) {
				for (int c = -1; c <= 1; c++) {
					if (r == 0 && c == 0)
						continue;
					if (valid_pos(i+r, j+c))
						if (map[i+r][j+c] == '@')
							rolls++;
				}
			}

			if (rolls < 4)
				total++;
		}
	}

	std::cout << total << std::endl;

	return 0;
}
