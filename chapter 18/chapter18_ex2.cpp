#include <iostream>

char* findx(const char* s, const char* x)
{
    if(*x == 0){
        return 0;
    }

    while (*s) {
        const char* tempS = s; // Store the current position of s for backtracking
        const char* tempX = x; // Store the beginning of x for comparison

        while (*tempS && *tempX && *tempS == *tempX) { // Compare characters of s and x
            ++tempS;
            ++tempX;
        }

        if (*tempX == '\0') // If we reached the end of x, it means we found the substring
            return const_cast<char*>(s);

        ++s; // Move to the next character in s for the next iteration
    }

    return nullptr; // If x is not found, return nullptr
}

int main()
{
    const char* s = "Function that finds the first occurence";
    const char* x = "the";
    
    char* result = findx(s, x);
    
    if (result != nullptr) {
        std::cout << "Substring '" << x << "' found at position " << (result - s) << std::endl;
    } else {
        std::cout << "Substring '" << x << "' not found in string '" << s << "'" << std::endl;
    }

    return 0;
}