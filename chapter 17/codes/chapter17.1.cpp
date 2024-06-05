#include <iostream>
#include <vector>

class vector{
public:
    vector(int s) : sz{s}, elem{new double[s]}{ };
    ~vector(){delete[] elem;}

    int size() const { return sz;}

    double get(int n) const {return elem[n];}
    void set(int n, double v) {elem[n] = v;}
    
private:
    int sz;
    double* elem;
};

int main()
{
    vector v(5);

    for(int i=0;i<v.size();i++){
        v.set(i,1.1*i);
        std::cout<<"v[ "<< i << " ] == "<<v.get(i)<<'\n'; 
    }
}