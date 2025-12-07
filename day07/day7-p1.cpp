#include <iostream>
#include <fstream>
#include <string>

#define ROWS 142
#define COLS 141

void traverse(char manifold[ROWS][COLS], int row, int col) {
	if (row >= ROWS)
		return;

	if (manifold[row][col] == '^') {
		if (manifold[row][col-1] == '.')
			traverse(manifold, row, col-1);
		if (manifold[row][col+1] == '.')
			traverse(manifold, row, col+1);
	} else {
		manifold[row][col] = '|';
		traverse(manifold, row+1, col);
	}
}

int main() {
	std::ifstream file;
	std::string data;

	char manifold[ROWS][COLS];
	int total = 0;

	int row = 0;
	int start_col = 0;

	file.open("input.txt");
	while(std::getline(file, data)) {
		for (int i = 0; i < COLS; i++)
			manifold[row][i] = data[i];
		row++;
	}

	for (int i = 0; i < COLS; i++) {
		if (manifold[0][i] == 'S') {
			start_col = i;
			break;
		}
	}

	traverse(manifold, 0, start_col);

	for (int i = 2; i < ROWS; i += 2) {
		for (int j = 1; j < COLS-1; j++) {
			if (manifold[i][j] == '^') {
				char top = manifold[i-1][j];
				char left = manifold[i][j-1];
				char right = manifold[i][j+1];
				if (top == '|' && left == '|' && right == '|')
					total++;
			}
		}
	}

	std::cout << total << std::endl;

	return 0;
}
