#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <cstdint>

int main() {
	std::ifstream file;
	std::string data;

	std::vector<std::pair<int, int>> positions;
	uint64_t largest_area = 0;

	file.open("input.txt");
	while(std::getline(file, data)) {
		size_t comma = data.find(',');
		int x = std::stoi(data.substr(0, comma));
		int y = std::stoi(data.substr(comma+1));
		positions.push_back({x, y});
	}

	for (int i = 0; i < positions.size(); i++) {
		for (int j = i+1; j < positions.size(); j++) {
			std::pair<int, int> a = positions[i];
			std::pair<int, int> b = positions[j];
			uint64_t width = abs(a.first - b.first) + 1;
			uint64_t height = abs(a.second - b.second) + 1;
			uint64_t area = width * height;
			largest_area = std::max(area, largest_area);
		}
	}

	std::cout << largest_area << std::endl;

	return 0;
}
