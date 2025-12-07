#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <utility>
#include <cstdint>

#define ROWS 142
#define COLS 141

uint64_t traverse(char manifold[ROWS][COLS], int row, int col, std::map<std::pair<int, int>, uint64_t>& cache) {
	if (row >= ROWS)
		return 1;

	std::pair<int, int> lookup = std::make_pair(row, col);
	std::map<std::pair<int, int>, uint64_t>::iterator it;

	it = cache.find(lookup);
	if (it != cache.end())
		return cache[lookup];

	if (manifold[row][col] == '^') {
		uint64_t lhs = traverse(manifold, row, col-1, cache);
		uint64_t rhs = traverse(manifold, row, col+1, cache);
		std::pair<int, int> split = std::make_pair(row, col);
		cache.insert({split, lhs + rhs});
		return lhs + rhs;
	} else {
		return traverse(manifold, row+1, col, cache);
	}
}

int main() {
	std::ifstream file;
	std::string data;

	char manifold[ROWS][COLS];

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

	std::map<std::pair<int, int>, uint64_t> cache;  // row, col => count

	uint64_t total = traverse(manifold, 0, start_col, cache);

	std::cout << total << std::endl;

	return 0;
}
