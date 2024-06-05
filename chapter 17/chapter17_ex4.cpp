#include <iostream>
#include <cstdlib>

char* strdup(const char* c)
{
    if(c == 0) return 0;

    int n = 0;
    while(c[n] != 0){
        n++;
    }

    char* p = new char[n+1];

    for(int i=0;c[i];i++){
        p[i] = c[i];
    }
    p[n] = 0;

    return p;
}

int main()
{
    std::string s;
    char* c;

    while(std::cin >> s && s != "quit"){
        c = strdup(s.c_str());
        std::cout << c << " ";
        delete[] c;
    }
    std::cout << '\n';

    return 0;
}