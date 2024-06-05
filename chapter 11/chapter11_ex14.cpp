#include <iostream>
#include <fstream>

int main()
{
    std::ifstream ifs("ifs_12.txt");
    if (!ifs) {
        std::cerr << "Error cant open file";
        return 0;
    }
    // read file into string
    // counter for character types
    char ch;
    int space = 0;  
    int alpha = 0;
    int digit = 0;
    int xdigit = 0;
    int upper = 0;
    int lower = 0;
    int alnum = 0;
    int cntrl = 0;
    int punct = 0;
    int print = 0;
    int graph = 0;

    while (ifs.get(ch)) {
        if (isspace(ch)) ++space;
        if (isalpha(ch)) ++alpha;
        if (isdigit(ch)) ++digit;
        if (isxdigit(ch)) ++xdigit;
        if (isupper(ch)) ++upper;
        if (islower(ch)) ++lower;
        if (isalnum(ch)) ++alnum;
        if (iscntrl(ch)) ++cntrl;
        if (ispunct(ch)) ++punct;
        if (isprint(ch)) ++print;
        if (isgraph(ch)) ++graph;
    }

    std::cout << "Analysis:\n";
    std::cout << "isspace:\t" << space << std::endl;
    std::cout << "isalpha:\t" << alpha << std::endl;
    std::cout << "isdigit:\t" << digit << std::endl;
    std::cout << "isxdigit:\t" << xdigit << std::endl;
    std::cout << "isupper:\t" << upper << std::endl;
    std::cout << "islower:\t" << lower << std::endl;
    std::cout << "isalnum:\t" << alnum << std::endl;
    std::cout << "iscntrl:\t" << cntrl << std::endl;
    std::cout << "ispunct:\t" << punct << std::endl;
    std::cout << "isprint:\t" << print << std::endl;
    std::cout << "isgraph:\t" << graph << std::endl;

    return 0;
}