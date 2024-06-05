#include <iostream>
#include <vector>
#include <list>
#include <iterator>


int main()
{
    int array1[10] = {0,1,2,3,4,5,6,7,8,9};

    std::vector<int> intvec1{0,1,2,3,4,5,6,7,8,9};

    std::list<int> intlist1{0,1,2,3,4,5,6,7,8,9};

    int array2[10];
    for(int i=0;i<10;i++){
        array2[i] = array1[i];
    }

    for(int i : array2){
        i+=2;
    }

    std::vector<int> intvec2 =  intvec1;
    
    for(int i : intvec2){
        i+=3;
    }
    
    std::list<int> intlist2 = intlist1;

    for(int i : intlist2){
        i+=5;
    }

}