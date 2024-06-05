#include <iostream>
#include <fstream>
#include <string>

void findWordInFile(const std::string& filename, const std::string& word) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;
        return;
    }

    std::string line;
    int lineNumber = 1;
    while (std::getline(file, line)) {
        if (line.find(word) != std::string::npos) {
            std::cout << "Line " << lineNumber << ": " << line << std::endl;
        }
        lineNumber++;
    }

    file.close();
}

int main() {
    std::string filename, word;

    // Input file name and word
    std::cout << "Enter the file name: ";
    std::getline(std::cin, filename);
    std::cout << "Enter the word to search: ";
    std::getline(std::cin, word);

    // Find and output lines containing the word
    findWordInFile(filename, word);

    return 0;
}
