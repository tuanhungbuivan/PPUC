#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class pvector{
private:
    std::vector<T*> v;

public:
    pvector() = default;

    ~pvector(){
        clear();
    }

    // Disable copy constructor and copy assignment operator
    pvector(const pvector&) = delete;
    pvector& operator=(const pvector&) = delete;

    // Enable move constructor and move assignment operator
    pvector(pvector&& other) noexcept : v(std::move(other.v)) { }

    pvector& operator=(pvector& other) noexcept{
        if(this != other){
            clear();
            v = std::move(other.v);
        }

        return *this;
    }

    void push_back(T* ptr){
        v.push_back(ptr);
    }

    T* operator[](size_t index) const{
        return v[index];
    }

    size_t size() const{
        return v.size();
    }

    void clear(){
        for(T* ptr : v){
            delete ptr;
        }
        
        v.clear();
    }
};

int main() 
{
    pvector<int> pv;

    for (int i = 0; i < 10; ++i) {
        pv.push_back(new int(i));
    }

    for (size_t i = 0; i < pv.size(); ++i) {
        std::cout << *pv[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}