#include <iostream>
#include <vector>
#include <string>
#include <iterator>

template<class Iterator>
Iterator lexicographical_last_element(Iterator first, Iterator last)
{
    if(first == last) return last;

    Iterator high = first;
    first++;
    while(first != last){
        if(*high < *first){
            high = first;
        }
        first++;
    }

    return high;
}

int main()
{
    std::vector<std::string> vs;
    
    std::string word;
    while(true){
        std::cin >> word;
        if(word == "quit") break;
        vs.push_back(word);
    }

    auto it = lexicographical_last_element(vs.begin(),vs.end());

    if (it != vs.end()) {
        std::cout << "The lexicographical last string is: " << *it << std::endl;
    } else {
        std::cout << "The vector is empty." << std::endl;
    }

    return 0;
}

