#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <vector>
#include <utility>

int main() {
	std::ifstream file;
	std::string data;

	std::vector<std::pair<uint64_t, uint64_t>> ranges;
	uint64_t total = 0;

	file.open("input.txt");
	std::getline(file, data);

	size_t i = 0;

	while(i < data.length()) {
		size_t comma = data.find(',', i);
		size_t capture = comma != std::string::npos ? comma : data.length();
		std::string id_range = data.substr(i, capture-i);

		size_t dash = id_range.find('-');
		uint64_t start = std::stoll(id_range.substr(0, dash));
		uint64_t end = std::stoll(id_range.substr(dash+1));

		ranges.push_back(std::make_pair(start, end));

		i = capture + 1;
	}

	for (std::pair<uint64_t, uint64_t> range : ranges) {
		for (uint64_t j = range.first; j <= range.second; j++) {
			std::string number = std::to_string(j);
			if (number.length() % 2 == 1)
				continue;
			size_t split = number.length() / 2;
			std::string lhs = number.substr(0, split);
			std::string rhs = number.substr(split);
			if (rhs[0] == '0')
				continue;
			if (lhs == rhs)
				total += j;
		}
	}

	std::cout << total << std::endl;

	return 0;
}
