#include <iostream>

template<class T>
class counted_ptr{
private:
    T* ptr;
    int* count;

public:
    explicit counted_ptr(T* p = nullptr) : ptr(p),  count(new int(1)){
        if(!p){
            *count = 0;
        }
    }

    // copy constructor
    counted_ptr(const counted_ptr& other) : ptr(other.ptr), count(other.count){
        if(ptr){
            (*count)++;
        }
    }
    
    // move constructor
    counted_ptr(counted_ptr&& other) noexcept : ptr(other.ptr), count(other.count){
        other.ptr = nullptr;
        other.count = nullptr;
    }

    // copy assignment operator
    counted_ptr& operator=(counted_ptr& other) {
        if(this != &other){
            cleanup();
            ptr = other.ptr;
            count = other.count;
            if(ptr){
                ++(*count);
            }
        }

        return *this;
    }

    // move assignment operator
    counted_ptr& operator=(counted_ptr&& other) noexcept{
        if(this != &other){
            cleanup();
            ptr = other.ptr;
            count = other.count;
            other.ptr = nullptr;
            other.count = nullptr;
        }

        return *this;
    }

    ~counted_ptr(){
        cleanup();
    }

    T& operator*() const{
        return *ptr;
    }

    T* operator->() const{
        return ptr;
    }

    T* get() const{
        return ptr;
    }

    int get_count() const{
        return *count;
    }

private:
    // Cleanup helper function
    void cleanup() {
        if (ptr && --(*count) == 0) {
            delete ptr;
            delete count;
        }
    }
};

int main() {
    {
        counted_ptr<int> p1(new int(10));
        std::cout << "p1 count: " << p1.get_count() << ", value: " << *p1 << std::endl;

        counted_ptr<int> p2 = p1;
        std::cout << "p1 count: " << p1.get_count() << ", p2 count: " << p2.get_count() << std::endl;

        counted_ptr<int> p3;
        p3 = p1;
        std::cout << "p1 count: " << p1.get_count() << ", p2 count: " << p2.get_count() << ", p3 count: " << p3.get_count() << std::endl;
    }

    {
        counted_ptr<int> p4(new int(20));
        std::cout << "p4 count: " << p4.get_count() << ", value: " << *p4 << std::endl;

        counted_ptr<int> p5 = std::move(p4);
        std::cout << "p5 count: " << p5.get_count() << ", value: " << *p5 << std::endl;

        counted_ptr<int> p6;
        p6 = std::move(p5);
        std::cout << "p6 count: " << p6.get_count() << ", value: " << *p6 << std::endl;
    }

    return 0;
}
