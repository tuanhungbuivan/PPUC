#include <iostream>

template <typename T>
struct Node{
    T data;
    Node* next;

    Node(const T& data) : data(data), next(nullptr) { }
};

template<typename T>
class Slist{
private:
    Node<T>* head;

public:
    Slist() : head(nullptr) { }

    ~Slist() {
        while(head){
            Node<T>* temp = head->next;
            delete head;
            head = temp;
        }
    }

    // Disable copy constructor and assignment operator
    Slist(const Slist&) = delete;
    Slist& operator=(const Slist&) = delete;

    void push_front(const T& value) {
        Node<T>* new_node = new Node(value);
        new_node->next = head;
        head = new_node;
    }

    void pop_front() {
        if(head){
            Node<T>* next = head->next;
            delete head;
            head = next;
        }
    }

    T& front() const {
        if(head){
            return head->data;
        }
        throw std::logic_error("List is empty");
    }

    bool empty() const {
        return head == nullptr;
    }

    void print() const {
        Node<T>* temp = head;
        while(temp != nullptr){
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << '\n';
    }
};


int main() {
    Slist<int> myList;

    myList.push_front(3);
    myList.push_front(2);
    myList.push_front(1);

    myList.print(); // Output: 1 2 3

    myList.pop_front();

    myList.print(); // Output: 2 3

    std::cout << "Front element: " << myList.front() << std::endl; // Output: Front element: 2

    return 0;
}