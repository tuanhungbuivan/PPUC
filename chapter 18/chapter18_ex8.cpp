#include <iostream>

char* cat_dot_backward(const char* s1, const char* s2, char c) {
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

    // Copy the second string into the result in reverse order
    char* tempResult = result;
    s2 += len2-1; // Move s2 to the end of the string
    while (len2--) {
        *tempResult = *s2;
        ++tempResult;
        --s2;
    }

    // Add the separator character
    *tempResult = c;
    ++tempResult;

    // Copy the first string into the result in reverse order
    s1 += len1-1; // Move s1 to the end of the string
    while (len1--) {
        *tempResult = *s1;
        ++tempResult;
        --s1;
    }

    // Add the null terminator
    *tempResult = '\0';

    return result;
}

int main() {
    const char* s1 = "Niels";
    const char* s2 = "Bohr";
    const char c = '-';

    char* result = cat_dot_backward(s1, s2, c);

    // Print the backward concatenated string
    std::cout << result << '\n';

    // Free the allocated memory
    delete[] result;

    return 0;
}
