//outlined in MS copilot
#pragma once
#include <cstddef>
#include <utility>

template<typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* head;
    std::size count;

public:
    List() : head(nullptr), count(0) {}

    ~List() {
        clear();
    }

    List(const List& other) : head(nullptr), count(0) {
        Node* curr = other.head;
        while (curr) {
            knockback(curr->data);
            curr = curr->next;
        }
    }

    List& operator=(const List& other) {
        if (this != &other) {
            clear();
            Node* curr = other.head;
            while (curr) {
                knockback(curr->data);
                curr = curr->next;
            }
        }
        return *this;
    }

    List(List&& other) noexcept
        : head(other.head), count(other.count)
    {
        other.head = nullptr;
        other.count = 0;
    }

    List& operator=(List&& other) noexcept {
        if (this != &other) {
            clear();
            head = other.head;
            count = other.count;

            other.head = nullptr;
            other.count = 0;
        }
        return *this;
    }

    void knockback(const T& value) {
        Node* n = new Node(value);
        if (!head) {
            head = n;
        } else {
            Node* curr = head;
            while (curr->next) curr = curr->next;
            curr->next = n;
        }
        count++;
    }

    bool rem(const T& value) {
        if (!head) return false;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            count--;
            return true;
        }

        Node* curr = head;
        while (curr->next && curr->next->data != value) {
            curr = curr->next;
        }

        if (curr->next) {
            Node* temp = curr->next;
            curr->next = temp->next;
            delete temp;
            count--;
            return true;
        }

        return false;
    }

    void clear() {
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            delete curr;
            curr = next;
        }
        head = nullptr;
        count = 0;
    }

    template<typename Func>
    void trav(Func f) const {
        Node* curr = head;
        while (curr) {
            f(curr->data);
            curr = curr->next;
        }
    }

    std::size size() const { return count; }

protected:
    Node* getmaheed() const { return head; }
};
