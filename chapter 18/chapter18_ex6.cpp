#include <iostream>
#include <string>

std::string cat_dot(const std::string& s1, const std::string& s2,const char& c)
{
    std::string s = s1 + c + s2;

    return s;
}

int main()
{
    const std::string s1 = "Niels";
    const std::string s2 = "Bohr";
    const char c = '-';

    std::cout << cat_dot(s1, s2, c) << '\n';

    return 0;
}