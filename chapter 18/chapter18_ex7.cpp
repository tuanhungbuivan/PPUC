#include <iostream>

char* cat_dot(const char* s1, const char* s2, char c) {
    // Find the lengths of the strings
    int len1 = 0, len2 = 0;
    const char* temp1 = s1;
    const char* temp2 = s2;
    while (*temp1) {
        ++len1;
        ++temp1;
    }
    while (*temp2) {
        ++len2;
        ++temp2;
    }

    // Allocate memory for the concatenated string
    char* result = new char[len1 + 1 + len2 + 1]; // +1 for the separator and +1 for the null terminator

    // Copy the first string into the result
    char* tempResult = result;
    while (*s1) {
        *tempResult = *s1;
        ++tempResult;
        ++s1;
    }

    // Add the separator character
    *tempResult = c;
    ++tempResult;

    // Copy the second string into the result
    while (*s2) {
        *tempResult = *s2;
        ++tempResult;
        ++s2;
    }

    // Add the null terminator
    *tempResult = '\0';

    return result;
}

int main() {
    const char* s1 = "Niels";
    const char* s2 = "Bohr";
    const char c = '-';

    char* result = cat_dot(s1, s2, c);

    // Print the concatenated string
    std::cout << result << '\n';

    // Free the allocated memory
    delete[] result;

    return 0;
}
