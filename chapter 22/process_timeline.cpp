#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <utility> // for std::pair

std::vector<std::pair<std::string, int> > read_pairs(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<std::pair<std::string, int> > pairs;
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string name;
        int year;

        if (std::getline(ss, name, ',') && ss >> year) {
            pairs.push_back(std::make_pair(name, year));
        }
    }

    return pairs;
}

void write_processed_pairs(const std::string& filename, const std::vector<std::pair<std::string, int> >& pairs) {
    std::ofstream file(filename);

    for (const std::pair<std::string, int>& pair : pairs) {
        file << pair.first << " " << pair.second << "\n";
    }
}

int main() {
    std::string input_file = "input.txt";
    std::string output_file = "processed_pairs.txt";

    std::vector<std::pair<std::string, int> > pairs = read_pairs(input_file);
    write_processed_pairs(output_file, pairs);

    std::cout << "Processed pairs written to " << output_file << std::endl;
    return 0;
}
