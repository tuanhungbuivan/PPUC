#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <set>
#include "text_cleaner.h"

void print_choices()
{
    std::cout << "What would you like to do?\n"
        << "1 - Clean text\n"
        << "2 - Get number of occurrences of a word\n"
        << "3 - Get most frequent word\n"
        << "4 - Get longest word\n"
        << "5 - Get shortest word\n"
        << "6 - Get words starting with a specific letter\n"
        << "7 - Get words of a specific length\n"
        << "0 - Exit\n";
}

void get_n_occurrences(const std::map<std::string, int>& map_words)
{
    if (map_words.size() == 0) {
        std::cout << "\nNo text loaded!\n\n";
        return;
    }

    std::cout << "Enter the word: ";
    std::string word;
    std::cin >> word;
    
    auto it = map_words.find(word);
    if(it != map_words.end()){
        std::cout << word << " occurs " << it->second << " times in the file\n";
    }else {
        std::cout << word << " does not occur in the file\n";
    }
}

void get_most_frequent(const std::map<std::string, int>& words)
{
    if (words.empty()) {
        std::cout << "\nNo text loaded!\n\n";
        return;
    }

    std::string most_frequent;
    int max = 0;
    for(const auto& pair : words){
        if(pair.second > max){
            max = pair.second;
            most_frequent = pair.first;
        }
    }

    std::cout << "most frequent word was: " << most_frequent << '\n';
}

void get_longest(const std::map<std::string,int>& words)
{
    if (words.empty()) {
        std::cout << "\nNo text loaded!\n\n";
        return;
    }

    std::string longest;
    for(const auto& pair : words){
        if(longest.length() < pair.first.length()){
            longest = pair.first;
        }
    }

    std::cout << "Longest word: " << longest << '\n';
}

void get_shortest(const std::map<std::string, int>& words)
{
    if (words.empty()) {
        std::cout << "\nNo text loaded!\n\n";
        return;
    }

    std::string shortest = words.begin()->first;
    for (const auto& pair : words) {
        if (pair.first.length() < shortest.length()) {
            shortest = pair.first;
        }
    }

    std::cout << "Shortest word: " << shortest << '\n';
}

void get_start_with(const std::map<std::string, int>& words)
{
    if (words.empty()) {
        std::cout << "\nNo text loaded!\n\n";
        return;
    }

    std::cout << "Enter the starting letter: ";
    char ch;
    std::cin >> ch;

    std::cout << "Words starting with '" << ch << "':\n";
    for(const auto& pair : words){
        if(!pair.first.empty() && pair.first[0] == ch){
            std::cout << pair.first << '\n';
        }
    }
}

void get_has_length(const std::map<std::string, int>& words)
{
    if (words.empty()) {
        std::cout << "\nNo text loaded!\n\n";
        return;
    }

    std::cout << "Enter the word length: ";
    size_t length;
    std::cin >> length;

    std::cout << "Words of length " << length << ":\n";
    for (const auto& pair : words) {
        if (pair.first.length() == length) {
            std::cout << pair.first << '\n';
        }
    }
}

int main()
{
    std::string input_file = "input.txt";  // Replace with your input file name
    std::string output_file = "cleaned_output.txt";  // Replace with your output file name
    clean_text(input_file, output_file);

    std::map<std::string, int> words;

    std::string file_name;

    bool keep_running = true;
    while(keep_running){
        print_choices();
        int n;
        std::cout << "Enter a number from 1 to 7: ";
        std::cin >> n;
        if (!std::cin) {
            std::cout << "\nPlease enter a number\n\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
            continue;
        }
        switch (n)
        {
        case 0:
            keep_running = false;
            break;
        case 1:
            words = clean_text(input_file, output_file);
            break;
        case 2:         // Get number of occurrences of a word
            get_n_occurrences(words);
            break;
        case 3:         // Get most frequent word
            get_most_frequent(words);
            break;
        case 4:         // Get longest word
            get_longest(words);
            break;
        case 5:         // Get shortest word
            get_shortest(words);
            break;
        case 6:         // Get words starting with a specific letter
            get_start_with(words);
            break;
        case 7:         // Get words of a specific length
            get_has_length(words);
            break;
        default:
            std::cout << "\nEnter a number between 1 and 7\n\n";
            break;
        }
        std::cout << '\n';
    }

    return 0;
}