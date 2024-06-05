#include <iostream>
#include <vector>
#include <list>
#include <iterator>

template<typename T, int N>
struct array{
    typedef T value_type;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef unsigned int size_type;

    T elem[N];

    iterator begin() { return elem; }
    const_iterator begin() const { return elem; }
    iterator end() { return elem+N; }
    const_iterator end() const { return elem+N; }

    size_type size() const { return N; }

    T& operator[](int n) { return elem[n]; }
    const T& operator[](int n) const { return elem[n]; }

    T* data() { return elem; }
    const T* data() const { return elem; }
};

template<typename Iter1, typename Iter2>
Iter2 copyf(Iter1 f1, Iter1 e1, Iter2 f2)
{
    while(f1!=e1){
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}

int main()
{
    array<int,10> array1= {0,1,2,3,4,5,6,7,8,9};

    std::vector<int> intvec1{0,1,2,3,4,5,6,7,8,9};

    std::list<int> intlist1{0,1,2,3,4,5,6,7,8,9};

    array<int,10> array2 = array1;
    for(array<int,10>::iterator p = array2.begin(); p != array2.end(); p++){
        *p+=2;
    }
 
    std::vector<int> intvec2 =  intvec1;
    for(std::vector<int>::iterator p = intvec2.begin(); p != intvec2.end(); p++){
        *p+=3;
    }

    for(std::vector<int>::iterator p = intvec2.begin(); p != intvec2.end(); p++){
            std::cout<<*p<<" ";

    }
    std::cout<<std::endl;
    std::vector<int>::iterator x = find(intvec2.begin(),intvec2.end(),3);
    std::cout<<"Index of 3 in x: "<< x - intvec2.begin()<<'\n';
    
    std::list<int> intlist2 = intlist1;
    for(int i : intlist2){
        i+=5;
    }

    copyf(array1.begin(),array1.end(),intvec2.begin());
    //if(intvec2[0] == intvec1[0]) std::cout<<intvec2[0];
    for(std::vector<int>::iterator p = intvec2.begin(); p != intvec2.end(); p++){
            std::cout<<*p<<" ";

    }
    std::cout<<std::endl;

    std::vector<int>::iterator a = find(intvec2.begin(),intvec2.end(),3);
    std::cout<<"Index of 3 in a: "<< a - intvec2.begin()<<'\n';
    /*
    if(x != intvec2.end()){
        int idx = 0;
        for(std::vector<int>::iterator p = intvec2.begin(); p != intvec2.end(); p++){
            idx++;
        }
        std::cout<<"x index of 3: "<<idx<<'\n';
    }
    */
}