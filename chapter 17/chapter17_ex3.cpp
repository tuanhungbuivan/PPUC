#include <iostream>

void to_lower(char* s)
{
    while(*s != '\0'){
        if(*s >= 'A' && *s <= 'Z'){
            *s = *s + ('a' - 'A');
        }
        s++;
    }
}

int main()
{
    char s[] = "HELLO WORLD!";
    std::cout << s << '\n';
    to_lower(s);

    std::cout << s << '\n';

    return 0;
}