#include <iostream>
#include <fstream>
#include <string>

void textToBinary(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file: " << inputFilename << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilename, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file: " << outputFilename << std::endl;
        return;
    }

    char c;
    while (inputFile.get(c)) {
        outputFile.write(reinterpret_cast<const char*>(&c), sizeof(char));
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Text file converted to binary successfully." << std::endl;
}

void binaryToText(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open input file: " << inputFilename << std::endl;
        return;
    }

    std::ofstream outputFile(outputFilename);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open output file: " << outputFilename << std::endl;
        return;
    }

    char c;
    while (inputFile.read(reinterpret_cast<char*>(&c), sizeof(char))) {
        outputFile.put(c);
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Binary file converted to text successfully." << std::endl;
}

int main() {
    std::string inputFilename = "input.txt";
    std::string outputFilename = "output.bin";
    textToBinary(inputFilename, outputFilename);
    /*
    std::string inputFilename1 = "input.bin";
    std::string outputFilename1 = "output.txt";
    binaryToText(inputFilename1, outputFilename1);
    */
    return 0;
}
