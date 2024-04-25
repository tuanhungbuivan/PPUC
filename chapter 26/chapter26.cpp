#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>


inline int randint(int max) { return max==0 ? 0 : rand()%max; }

template<typename T>
struct Test{
    std::string label;
    T val;
    std::vector<T> seq;
    bool res;
};

template<typename T>
std::istream& operator>>(std::istream& is, Test<T>& t)
{
    is >> t.label >> t.val;
    int seq_size;
    is >> seq_size;
    t.seq.resize(seq_size);
    for(auto& elem : t.seq)
        is >> elem;
    is >> t.res;
    return is;
}

template<typename T>
int test_all(std::istream& is)
{
    int error_count = 0;
    for(Test<T> t; is >> t;){
        bool r = std::binary_search(t.seq.begin(),t.seq.end(),t.val);
        std::cout << "Test case: " << t.label << ", val: " << t.val << ", seq size: " << t.seq.size() << std::endl;
        std::cout << "Binary search result: " << std::boolalpha << r << ", Expected result: " << t.res << std::endl;
        if(r != t.res){
            std::cout<< "failure: test "<< t.label 
                << " binary_search: " << t.seq.size() << " elemnents, val==" << t.val 
                << " -> " << t.res <<'\n';
            ++error_count;
        }
    }

    return error_count;
}

void make_test(const std::string& lab, int n, int base, int spread)
{
    std::cout<<"{ " << lab << " " << n << " {";
    std::vector<int> v;
    int elem = base;
    for(int i = 0; i < n; ++i){
        elem += randint(spread);
        v.push_back(elem);
    }

    int val = base + randint(elem - base);
    bool found = false;
    for(int i = 0; i < n; i++){
        if(v[i] == val) found = true;
        std::cout<< v[i] << " ";
    }
    std::cout<<"} " << found << " }\n";
}

int main()
{
    std::ifstream file("my_test.txt");
    int errors = test_all<int>(file);
    std::cout<<"number of errors: "<< errors << '\n';

    int no_of_test = randint(10);
    for(int i = 0; i < no_of_test; i++){
        std::string lab = "rand_test_";
        make_test(lab+std::to_string(i),randint(20),0,randint(10));
    }

    std::ifstream file1("my_test1.txt");
    int errors1 = test_all<int>(file1);
    std::cout<<"number of errors: "<< errors1 << '\n';
}