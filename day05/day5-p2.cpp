#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <utility>
#include <vector>

int main() {
	std::ifstream file;
	std::string data;

	std::vector<std::pair<uint64_t, uint64_t>> ranges;
	uint64_t total = 0;

	file.open("input.txt");
	while(std::getline(file, data)) {
		if (data == "")
			break;

		size_t dash = data.find('-');
		uint64_t start = std::stoll(data.substr(0, dash));
		uint64_t end = std::stoll(data.substr(dash+1));
		ranges.push_back(std::make_pair(start, end));
	}

	bool overlap;

	do {
		overlap = false;
		int remove_index;

		for (int i = 0; i < ranges.size() && !overlap; i++) {
			for (int j = 0; j < ranges.size() && !overlap; j++) {
				if (i == j)
					continue;
				uint64_t a_start = ranges[i].first;
				uint64_t a_end = ranges[i].second;
				uint64_t b_start = ranges[j].first;
				uint64_t b_end = ranges[j].second;

				if (a_start <= b_start && a_end >= b_start) {
					if (a_end <= b_end)
						ranges[i].second = ranges[j].second;
					remove_index = j;
					overlap = true;
				}
			}
		}

		if (overlap)
			ranges.erase(ranges.begin()+remove_index);
	} while(overlap);

	for (std::pair<uint64_t, uint64_t> range : ranges)
		total += range.second - range.first + 1;

	std::cout << total << std::endl;

	return 0;
}
