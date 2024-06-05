#include <list>
#include <vector>
#include <iostream>
#include <iterator>

void copy_list(const std::list<int>& l)
{
    std::vector<int> v;
    std::list<int>::const_iterator l_it = l.begin();
    while (l_it != l.end())
    {
        v.push_back(*l_it);
        ++l_it;
    }
    
    for (int val : v) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::list<int> l;
    for(int i=0;i<10;i++){
        l.push_back(i);
    }

    copy_list(l);

    return 0;
}