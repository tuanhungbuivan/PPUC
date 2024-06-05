#include <iostream>
#include <vector>
#include <list>
#include <string>

bool v_binary_search(std::vector<int>& v, int target)
{
    int left = 0;
    int right = v.size();

    while(left <= right){
        int mid = left + (right - left) / 2;

        if(v[mid] == target){
            return true;
        }else if(v[mid] < target){
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }

    return false;
}

bool l_binary_search(const std::list<std::string>& l, const std::string& word)
{
    auto first = l.begin();
    auto last = l.end();

    while(first != last){
        auto mid = std::next(first, std::distance(first,last)/2);

        if(*mid == word){
            return true;
        }else if(*mid < word){
            first = std::next(mid);
        }else{
            last = mid;
        }
    }

    return false;
}

int main()
{
    std::vector<int> v;
    for(int i=1;i<=10;i++){
        v.push_back(i+2+1);
    }

    std::cout << v_binary_search(v, 5) << std::endl; // Should print 1 (true)
    std::cout << v_binary_search(v, 2) << std::endl; // Should print 0 (false)

    std::list<std::string> lst = {"apple", "banana", "cherry", "grape", "orange"};

    std::cout << l_binary_search(lst, "cherry") << std::endl; // Should print 1 (true)
    std::cout << l_binary_search(lst, "pear") << std::endl; // Should print 0 (false)

    return 0;
}