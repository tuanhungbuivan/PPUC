#include <iostream>
#include <vector>
#include <iterator>

// Custom find function template
template<class Iter, class T>
Iter custom_find(Iter first, Iter last, const T& val)
{
    while (first != last) {
        if (*first == val) {
            return first; // Found the element, return iterator pointing to it
        }
        ++first;
    }
    return last; // Return last if element is not found
}

// Custom count function template
template<class Iter, class T>
int custom_count(Iter first, Iter last, const T& val)
{
    int counter = 0;
    while (first != last) {
        if (*first == val) {
            ++counter; // Increment counter if element is found
        }
        ++first;
    }
    return counter;
}

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};

    // Using custom find function
    auto it_custom = custom_find(v.begin(), v.end(), 5);
    if (it_custom != v.end()) {
        std::cout << "Custom find: Element found at index " << std::distance(v.begin(), it_custom) << std::endl;
    } else {
        std::cout << "Custom find: Element not found" << std::endl;
    }

    // Using standard find function
    auto it_std = std::find(v.begin(), v.end(), 5);
    if (it_std != v.end()) {
        std::cout << "Standard find: Element found at index " << std::distance(v.begin(), it_std) << std::endl;
    } else {
        std::cout << "Standard find: Element not found" << std::endl;
    }

    // Using custom count function
    int count_custom = custom_count(v.begin(), v.end(), 3);
    std::cout << "Custom count: Element found " << count_custom << " times" << std::endl;

    // Using standard count function
    int count_std = std::count(v.begin(), v.end(), 3);
    std::cout << "Standard count: Element found " << count_std << " times" << std::endl;

    return 0;
}
