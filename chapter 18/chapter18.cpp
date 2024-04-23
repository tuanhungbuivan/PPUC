#include <iostream>
#include <vector>

int main()
{
    std::vector<double> *p = new std::vector<double>(10);
    int n=0;
    for(double d; std::cin>>d;){
        if(n==p->size()){
            std::vector<double> *q = new std::vector<double>(p->size()*2);
            copy(p->begin(),p->end(),q->begin());
            delete p;
            p=q;
            break;
        }
        (*p)[n] = d;
        n++;
    }

    std::cout << "Elements in the vector:" << std::endl;
    for (const auto& element : *p) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    delete p; // Don't forget to delete the dynamically allocated vector
    return 0;
}