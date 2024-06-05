#include <iostream>

class Link{
public:
    std::string name;
    Link* next;

    Link(const std::string& name, Link* next = nullptr) : name(name), next(next) { }
};

class LinkedList{
public:
    // constructor
    LinkedList () : head(nullptr) { }

    // destructor
    ~LinkedList(){
        while(head != nullptr){
            Link* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(const std::string& name);
    void erase(const std::string& name);
    Link* find(const std::string& s) const;
    LinkedList* advance(int n) const;
    void add(const std::string& name, int n);
    void print();

private:
    Link* head;
};

void LinkedList::insert(const std::string& name)
{
    head = new Link(name,head);
}

void LinkedList::erase(const std::string& name)
{
    Link* current = head;
    Link* prev = nullptr;

    while(current != nullptr){
        if(current->name == name){
            if(prev == nullptr){
                head = current->next;
            }else{
                prev->next = current->next;
            }
            delete current;
            return;
        }
        prev = current;
        current = current->next;
    }
}

Link* LinkedList::find(const std::string& s) const
{
    Link* current = head;
    while(current != nullptr){
        if(current->name == s){
            return current;
        }
        current = current->next;
    }

    return nullptr;
}

LinkedList* LinkedList::advance(int n) const {
    LinkedList* list = new LinkedList();
    Link* current = head;

    while (n > 0 && current != nullptr) {
        list->insert(current->name);
        current = current->next;
        n--;
    }

    return list;
}

void LinkedList::add(const std::string& name, int n)
{
    if(n <= 0){
        insert(name);
        return;
    }

    Link* current = head;
    Link* prev = nullptr;

    while(n > 0 && current != nullptr){
        prev = current;
        current = current->next;
        n--;
    }

    if(prev == nullptr){
        insert(name);
    }else{
        prev->next = new Link(name,current);
    }
}

void LinkedList::print()
{
    Link* current = head;

    while(current != nullptr){
        std::cout << current->name << " ";
        current = current->next;
    }
    std::cout << '\n';
}

int main()
{

    LinkedList List;

    List.insert("Thor");
    List.insert("Odin");
    List.insert("Freya");

    List.add("Zeus",2);

    List.print();

    List.erase("Freya");
    List.print();

    return 0;
}