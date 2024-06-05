//  Write a program that produces the sum of all the numbers in a file of
//  whitespace-separated integers.

#include <iostream>
#include <fstream>
#include <vector>

const std::string if_name("file10.1.txt");

void read_numbers(std::vector<int>& v, const std::string& file)
{
    std::ifstream ist(file);

    if(!ist) {std::cout<<"Cant open file \n"; return;}
    ist.exceptions(ist.exceptions()|std::ios_base::badbit);

    for(int n; ist >> n; ) v.push_back(n);

    if(ist.eof()){
        ist.clear();
        std::cout<<"File " << file << " completely read: "<< v.size() << " numbers. \n";
    }

    if(ist.fail()) {std::cout<<"not well formatted file \n" << file; return; }
}


int check_add(int l, int r)
{
    if(((r > 0) && (l > (std::numeric_limits<int>::max() - r))) ||
       ((l < 0) && (l < (std::numeric_limits<int>::min() - r)))){
            std::cout<<"intreger add overflow \n";
            return 0;
    }else{
        return r+l;
    }
            
}

int sum(const std::vector<int>& v)
{
    int sum{0};
    for(int n : v) sum = check_add(sum,n);
    return sum;
}

int main()
{
    std::vector<int> numbers;

    read_numbers(numbers, if_name);
    std::cout<<"The sum of numbers "<<if_name<<" is "<< sum(numbers)<<'\n';

    return 0;
}