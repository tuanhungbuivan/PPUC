#include <iostream>

int main()
{
    std::string s;
    char c;
    while(std::cin >> c && c != '!'){
        s.push_back(c);
    }

    return 0;
}