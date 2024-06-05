#include <iostream>
#include <fstream>
#include <string>
#include <regex>
#include <vector>

std::vector<std::regex> get_date_patterns() {
    std::vector<std::regex> patterns;
    // Simple MM/DD/YYYY format
    patterns.push_back(std::regex(R"(\b(0[1-9]|1[0-2])/(0[1-9]|[12][0-9]|3[01])/(\d{4})\b)"));
    // Add more patterns here if needed
    // e.g., DD/MM/YYYY
    patterns.push_back(std::regex(R"(\b(0[1-9]|[12][0-9]|3[01])/(0[1-9]|1[0-2])/(\d{4})\b)"));
    // YYYY-MM-DD
    patterns.push_back(std::regex(R"(\b(\d{4})-(0[1-9]|1[0-2])-(0[1-9]|[12][0-9]|3[01])\b)"));
    // Month DD, YYYY
    patterns.push_back(std::regex(R"(\b(January|February|March|April|May|June|July|August|September|October|November|December) (0[1-9]|[12][0-9]|3[01]), (\d{4})\b)"));
    return patterns;
}

bool contains_date(const std::string& line, const std::vector<std::regex>& patterns) {
    for (const auto& pattern : patterns) {
        if (std::regex_search(line, pattern)) {
            return true;
        }
    }
    return false;
}

void find_dates_in_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        return;
    }

    std::vector<std::regex> patterns = get_date_patterns();
    std::string line;
    int line_number = 0;

    while (getline(file, line)) {
        ++line_number;
        if (contains_date(line, patterns)) {
            std::cout << "Line " << line_number << ": " << line << "\n";
        }
    }
}

int main() {
    std::string filename = "your_text_file.txt"; // Replace with your file name
    find_dates_in_file(filename);
    return 0;
}
