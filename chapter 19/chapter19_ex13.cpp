#include <iostream>

class Tracer{
private:
    std::string message;

public:
    Tracer(const std::string& s) : message(s){
        std::cout << "constructor: " << message << '\n';
    }

    ~Tracer(){
        std::cout << "destructor: " << message << '\n';
    }

    Tracer(const Tracer& other) {
        std::cout << "copy constructor: " << message << '\n'; 
    }

    Tracer& operator=(const Tracer& other){
        if(this != &other){
            message = other.message;
            std::cout << "copy assignment: " << message << '\n';
        }

        return *this;
    }

};

// Function to demonstrate local object
void local_tracer() {
    Tracer t("Local Tracer");
}

// Global object
Tracer global_tracer("Global Tracer");

int main() {
    std::cout << "Start of main" << std::endl;

    // Local scope
    {
        Tracer t1("Local Scope Tracer 1");
        Tracer t2("Local Scope Tracer 2");

        // Copy construction
        Tracer t3 = t1;

        // Copy assignment
        t2 = t1;
    }

    // Dynamic allocation
    Tracer* t4 = new Tracer("Dynamically Allocated Tracer");
    delete t4;

    std::cout << "End of main" << std::endl;

    return 0;
}