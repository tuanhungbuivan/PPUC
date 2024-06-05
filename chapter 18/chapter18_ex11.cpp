#include <iostream>
#include <cstdlib>
#include <ctime>

struct Node{
    int value;
    Node** next;
    int levels;

    Node(int value, int levels) : value(value), levels(levels){
        next = new Node*[levels];
        for(int i=0;i<levels;i++){
            next[i] = nullptr;
        }
    }
    ~Node() {
        delete[] next;
    }
};

class Skip_list{
private:
    int maxLevels;
    Node* head;

public:

    Skip_list(int maxLevels) : maxLevels(maxLevels){
        head = new Node(INT_MIN,maxLevels);
    }

    ~Skip_list() {
        Node* current = head->next[0];
        while(current != nullptr){
            Node* temp = current;
            current = current->next[0];
            delete temp;
        }

        delete head;
    }

    bool search(int value){
        Node* current = head;
        for(int i = maxLevels - 1; i>=0; i--){
            while(current->next[i] && current->next[i]->value < value){
                current = current->next[i];
            }
        }
        current = current->next[0];
        return current && current->value == value;
    }

    void insert(int value){
        int level = randomlevels();
        Node* newnode = new Node(value,level);
        Node* current = head;

        for(int i=maxLevels-1; i>=0; i--){
            while(current->next[i] && current->next[i]->value < value){
                current = current->next[i];
            }
            if(i < level){
                newnode->next[i] = current->next[i];
                current->next[i] = newnode;
            }
        }
    }

    void remove(int value){
        Node* current = head;
        Node* todelete = nullptr;

        for(int i=maxLevels-1; i>=0; i--){
            while(current->next[i] && current->next[i]->value < value){
                current = current->next[i];
            }
            if(current->next[i] && current->next[i]->value == value){
                todelete = current->next[i];
                current->next[i] = todelete->next[i];
            }
        }

        delete todelete;
    }

    void print() {
        for (int i = maxLevels - 1; i >= 0; --i) {
            Node* current = head->next[i];
            std::cout << "Level " << i + 1 << ": ";
            while (current) {
                if (current->value != INT_MAX) {
                    std::cout << " " << current->value << " ";
                } else {
                    std::cout << " nullptr ";
                }
                if (current->next[i] != nullptr && current->next[i]->value != INT_MAX) {
                    std::cout << " -> ";
                }
                current = current->next[i];
            }
            std::cout << std::endl;
        }
    }


private:
    int randomlevels() {
        int levels = 1;
        while(rand() % 2 == 0 && levels < maxLevels){
            levels++;
        }

        return levels;
    }
};

int main()
{
    srand(time(nullptr));
    Skip_list skip(4);

    skip.insert(3);
    skip.insert(2);
    skip.insert(9);
    skip.insert(5);
    skip.insert(8);
    skip.insert(6);

    std::cout << "Search 6: " << (skip.search(6) ? "Found" : "Not found") << std::endl;
    std::cout << "Search 5: " << (skip.search(5) ? "Found" : "Not found") << std::endl;

    skip.remove(6);

    std::cout << "Search 6 after deletion: " << (skip.search(6) ? "Found" : "Not found") << std::endl;

    skip.print();
    return 0;
}