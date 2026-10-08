//outlined with MS copilot
#include <utility>   
#include <stdexcept> 

template <typename T>
class LinkedList {
private:
    struct Node {
        std::pair<T, unsigned int> data;  
        Node* next;

        Node(const std::pair<T, unsigned int>& d)
            : data(d), next(nullptr) {}
    };

    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insertAt(const std::pair<T, unsigned int>& item, unsigned int index) {
        Node* newNode = new Node(item);

        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* curr = head;
        for (unsigned int i = 0; i < index - 1; i++) {
            if (curr == nullptr)
                throw std::out_of_range("Index out of range");
            curr = curr->next;
        }

        newNode->next = curr->next;
        curr->next = newNode;
    }

    void removeFront() {
        if (head == nullptr)
            throw std::out_of_range("List is empty");

        Node* temp = head;
        head = head->next;
        delete temp;
    }

    std::pair<T, unsigned int>& front() {
        if (head == nullptr)
            throw std::out_of_range("List is empty");
        return head->data;
    }

    bool empty() const {
        return head == nullptr;
    }

    unsigned int findInsertIndex(unsigned int priority) const {
        unsigned int index = 0;
        Node* curr = head;

        while (curr != nullptr && curr->data.second >= priority) {
            curr = curr->next;
            index++;
        }

        return index;
    }
};


template <typename T>
class PriorityQueue {
private:
    LinkedList<T> list;

public:
    PriorityQueue() {}

    void push(T newItem, unsigned int itemPriority) {
        std::pair<T, unsigned int> p(newItem, itemPriority);

        unsigned int index = list.findInsertIndex(itemPriority);
        list.insertAt(p, index);
    }

    T& top() {
        return list.front().first;
    }

    void pop() {
        list.removeFront();
    }

    bool empty() const {
        return list.empty();
    }
};

/*
    This linked‑list priority queue is not the best way to make a priority queue.
    push() is O(n) because we must traverse the list to find the correct
    insertion point. pop() and top() are O(1), basically meaning it scans the whole list
    to locate an item to pop() which is way less efficient than a proper queue.
*/
