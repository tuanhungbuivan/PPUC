#include <iostream>

void replace(std::string& a)
{

    for(int i=0;i<a.length();i++){
        if(a[i] == '.' || a[i] == '-' || a[i] == ';' || a[i] == '?' || ispunct(a[i])) a[i] = ' ';
        else a[i] = tolower(a[i]);
    }
}


int main()
{

    std::string a =" - Don't use the as-if Rule.";

    replace(a);

    std::cout << a << std::endl;
    return 0;
}