#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <algorithm>
#include <cstdlib>

int main()
{
    std::ifstream ifs("ifs8.txt");
    if(!ifs){
        std::cerr << "Error cant opent file'\n";
        exit(EXIT_FAILURE);
    }

    std::map<std::string, int> word_count;
    std::string word;
    while(ifs >> word){
        ++word_count[word];
    }

    std::vector<std::pair<int, std::string>> v_words;
    for(const auto& p : word_count){
        v_words.push_back(std::make_pair(p.second, p.first));
    }

    std::sort(v_words.begin(), v_words.end());

    for(const auto& p : v_words){
        std::cout << p.second << ": " << p.first << '\n';
    }

    return 0;
}