#include <iostream>
#include <string>

std::string cat_dot(const std::string& s1, const std::string& s2)
{
    std::string s = s1 + '.' + s2;

    return s;
}

int main()
{
    const std::string s1 = "Niels";
    const std::string s2 = "Bohr";

    std::cout << cat_dot(s1, s2) << '\n';

    return 0;
}