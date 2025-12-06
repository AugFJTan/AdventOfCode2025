#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <utility>
#include <vector>

int main() {
	std::ifstream file;
	std::string data;
	bool id_range = true;

	std::vector<std::pair<uint64_t, uint64_t>> ranges;
	int total = 0;

	file.open("input.txt");
	while(std::getline(file, data)) {
		if (data == "") {
			id_range = false;
			continue;
		}

		if (id_range) {
			size_t dash = data.find('-');
			uint64_t start = std::stoll(data.substr(0, dash));
			uint64_t end = std::stoll(data.substr(dash+1));
			ranges.push_back(std::make_pair(start, end));
		} else {
			uint64_t id = std::stoll(data);
			bool fresh = false;

			for (std::pair<uint64_t, uint64_t> range : ranges) {
				if (id >= range.first && id <= range.second)
					fresh = true;
			}

			if (fresh)
				total++;
		}
	}

	std::cout << total << std::endl;

	return 0;
}
