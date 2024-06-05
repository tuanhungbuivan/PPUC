#include <iostream>
#include <fstream>

int main()
{
    std::cout << "Enter file name ifstream: ";
    std::string name;
    std::cin >> name;
    std::ifstream ifs(name.c_str());

    if(!ifs) std::cerr << "Wrong file name\n";

    std::cout << "Enter file name ofstream: ";
    std::string name1;
    std::cin >> name1;
    std::ofstream ofs(name1.c_str());

    if(!ofs) std::cerr << "Wrong file name\n";

    char c;
    while(ifs.get(c)){
        if(isalpha(c)) c = tolower(c);
        ofs << c;
    }

    return 0;
}