#include <iostream>
#include <cstring>

bool is_palindrome(const char s[],int n)
{
    int first = 0;
    int last = n - 1;
    while(first < last){
        if(s[first] != s[last]){
            return false;
        }
        first++;
        last--;
    }
    return true;
}

std::istream& read_word(std::istream& is,char* buffer, int max)
{
    is.width(max);
    is >> buffer;
    while(std::strlen(buffer) == max -1){
        std::cout << "Input cut off after " << max - 1 << "characters" << std::endl;
        char c;
        while(is.get(c)){
            if(c == '\n'){
                break;
            }
        }
    }

    return is;
}

std::istream& read_long_word(std::istream& is, char*& buffer) {
    const int initial_max = 128;
    int max = initial_max;
    char* temp1 = new char[max];
    *temp1 = '\0'; // Ensure the string is properly terminated
    char ch;
    int length = 0;

    while (is.get(ch)) {
        if (ch == '\n') break;
        if (length == max - 1) {
            // Double the length of temp1
            char* temp2 = new char[max * 2];
            strcpy(temp2, temp1);
            delete[] temp1;
            max *= 2;
            temp1 = temp2;
        }
        temp1[length++] = ch; // Add character to the string and increment the length
        temp1[length] = '\0'; // Ensure the string is properly terminated
    }
    buffer = temp1;
    return is;
}

int main()
{
    constexpr int max= 128;
    char s[max];
    while(read_word(std::cin,s,max) && strcmp(s,"quit")){
        std::cout << s << " is";
        if(!is_palindrome(s,strlen(s))){
            std::cout << " not";
        }
        std::cout << " a palindrome\n";
    }

    return 0;
}