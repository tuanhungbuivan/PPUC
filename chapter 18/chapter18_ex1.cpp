#include <iostream>

char* strup(const char* str)
{
    int length = 0;
    const char* temp = str;
    while(*temp){
        length++;
        temp++;
    }

    // Allocate memory on a free store
    char* newstr = new char[length+1]; // +1 for the null terminator

    // Copy the characters from the input string to the allocated memory
    char* tempnewstr = newstr; // tempNewStr points to the beginning of the allocated memory
    while(*str){
        *tempnewstr = *str;
        str++;
        tempnewstr++;
    }

    *tempnewstr = '\0';

    return newstr;
}

int main()
{
    const char* original = "Written to coppy";
    char* copied = strup(original);

    std::cout << original << '\n';
    std::cout << "copied from original: " << copied;
    std::cout << '\n';

    delete[] copied;

    return 0;
}