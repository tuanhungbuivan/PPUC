#include <iostream>

template<class T>
class Uniqueptr {
public:
    // Constructor
    explicit Uniqueptr(T* p = nullptr) : ptr(p) {}

    // Destructor
    ~Uniqueptr() {
        delete ptr;
    }

    // Dereference operator
    T& operator*() const {
        return *ptr;
    }

    // Member access operator
    T* operator->() const {
        return ptr;
    }

    // Release method
    T* release() {
        T* oldptr = ptr;
        ptr = nullptr;
        return oldptr; // Do not delete the pointer here
    }

    // Disable copy constructor
    Uniqueptr(const Uniqueptr&) = delete;

    // Disable copy assignment operator
    Uniqueptr& operator=(const Uniqueptr&) = delete;

    // Move constructor
    Uniqueptr(Uniqueptr&& other) noexcept : ptr(other.ptr) {
        other.ptr = nullptr;
    }

    // Move assignment operator
    Uniqueptr& operator=(Uniqueptr&& other) noexcept {
        if (this != &other) {
            delete ptr;
            ptr = other.ptr;
            other.ptr = nullptr;
        }
        return *this;
    }

private:
    T* ptr; 
};

int main() {
    Uniqueptr<int> up1(new int(42));
    std::cout << *up1 << std::endl;

    int* rawPtr = up1.release();
    std::cout << *rawPtr << std::endl;
    delete rawPtr;

    // Move semantics demonstration
    Uniqueptr<int> up2(new int(100));
    Uniqueptr<int> up3 = std::move(up2);
    std::cout << *up3 << std::endl;

    return 0;
}
