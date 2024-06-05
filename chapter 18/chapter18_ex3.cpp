#include <iostream>

int strcmp(const char* s1, const char* s2) {
    while (*s1 && *s2 && *s1 == *s2) {
        ++s1;
        ++s2;
    }

    if (*s1 < *s2) {
        return -1;
    } else if (*s1 > *s2) {
        return 1;
    }

    return 0;
}

int main() {
    const char* s1 = "hello";
    const char* s2 = "world";

    int result = strcmp(s1, s2);

    if (result < 0) {
        std::cout << "s1 is lexicographically before s2" << std::endl;
    } else if (result > 0) {
        std::cout << "s1 is lexicographically after s2" << std::endl;
    } else {
        std::cout << "s1 is lexicographically equal to s2" << std::endl;
    }

    return 0;
}