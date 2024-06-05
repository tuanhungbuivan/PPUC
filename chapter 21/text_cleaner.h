#ifndef TEXT_CLEANER_H
#define TEXT_CLEANER_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <unordered_map>
#include <unordered_set>
#include <map>

// Function to handle contractions
std::string handle_contradiction(const std::string& word)
{
    std::unordered_map<std::string, std::string> contractions = {
        {"don't", "do not"}, {"can't", "cannot"}, {"won't", "will not"},
        {"it's", "it is"}, {"I'm", "I am"}, {"you're", "you are"},
        {"they're", "they are"}, {"we're", "we are"}, {"isn't", "is not"},
        {"aren't", "are not"}, {"wasn't", "was not"}, {"weren't", "were not"},
        {"hasn't", "has not"}, {"haven't", "have not"}, {"hadn't", "had not"},
        {"doesn't", "does not"}, {"didn't", "did not"}, {"wouldn't", "would not"},
        {"shan't", "shall not"}, {"shouldn't", "should not"}, {"mightn't", "might not"},
        {"mustn't", "must not"}
    };

    auto it = contractions.find(word);
    if (it != contractions.end()) {
        return it->second;
    }

    return word;
}

// Function to remove plural forms
std::string remove_plural(std::string& word, std::unordered_set<std::string>& word_set)
{
    if (word.size() > 1 && word.back() == 's') {
        std::string singular = word.substr(0, word.size() - 1);
        if (word_set.find(singular) != word_set.end()) {
            return singular;
        } else {
            word_set.insert(singular);
            return singular;
        }
    }

    return word;
}

// Function to clean text
std::map<std::string, int> clean_text(const std::string& input_file, const std::string& output_file)
{
    std::ifstream ifs(input_file);
    if (!ifs) {
        std::cerr << "Error: can't open file '" << input_file << "'\n";
        exit(EXIT_FAILURE);
    }

    std::stringstream buffer;
    buffer << ifs.rdbuf();
    std::string text = buffer.str();

    std::unordered_set<std::string> word_set;
    std::string word;
    std::string cleaned_word;

    for (char& c : text) {
        if (isalpha(c) || c == '\'') {
            word += std::tolower(c);
        } else {
            if (!word.empty()) {
                std::string processed_word = handle_contradiction(word);
                word_set.insert(processed_word);
                cleaned_word += processed_word + ' ';
                word.clear();
            }
            if (std::isspace(c)) {
                cleaned_word += ' ';
            }
        }
    }

    if (!word.empty()) {
        std::string processed_word = handle_contradiction(word);
        word_set.insert(processed_word);
        cleaned_word += processed_word;
    }

    std::ofstream ofs(output_file);
    if (!ofs) {
        std::cerr << "Error: can't open file '" << output_file << "'\n";
        exit(EXIT_FAILURE);
    }

    std::istringstream iss(cleaned_word);
    std::string cleaned;
    std::string final_text;

    std::map<std::string, int> map_words;

    while (iss >> cleaned) {
        cleaned = remove_plural(cleaned, word_set);
        map_words[cleaned]++;
        final_text += cleaned + ' ';
    }

    ofs << final_text;

    return map_words;
}

#endif // TEXT_CLEANER_H
