//outlined with MS copilot
#pragma once
#include <cstddef>
#include <memory>
#include <utility>

template<typename T>
class List {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;

        Node(const T& d) : data(d), next(nullptr) {}
    };

    std::unique_ptr<Node> head;
    std::size_t count;

public:
    List() : head(nullptr), count(0) {}

    ~List() = default; // smart pointers handle cleanup

    // Copy constructor
    List(const List& other) : head(nullptr), count(0) {
        Node* curr = other.head.get();
        while (curr) {
            knockback(curr->data);
            curr = curr->next.get();
        }
    }

    // Copy assignment
    List& operator=(const List& other) {
        if (this != &other) {
            clear();
            Node* curr = other.head.get();
            while (curr) {
                knockback(curr->data);
                curr = curr->next.get();
            }
        }
        return *this;
    }

    // Move constructor
    List(List&& other) noexcept
        : head(std::move(other.head)), count(other.count)
    {
        other.count = 0;
    }

    // Move assignment
    List& operator=(List&& other) noexcept {
        if (this != &other) {
            clear();
            head = std::move(other.head);
            count = other.count;
            other.count = 0;
        }
        return *this;
    }

    // Push to back
    void knockback(const T& value) {
        auto n = std::make_unique<Node>(value);

        if (!head) {
            head = std::move(n);
        } else {
            Node* curr = head.get();
            while (curr->next) {
                curr = curr->next.get();
            }
            curr->next = std::move(n);
        }
        count++;
    }

    // Remove first matching value
    bool rem(const T& value) {
        if (!head) return false;

        // Remove head
        if (head->data == value) {
            head = std::move(head->next);
            count--;
            return true;
        }

        Node* curr = head.get();
        while (curr->next && curr->next->data != value) {
            curr = curr->next.get();
        }

        if (curr->next) {
            curr->next = std::move(curr->next->next);
            count--;
            return true;
        }

        return false;
    }

    void clear() {
        head.reset();
        count = 0;
    }

    template<typename Func>
    void trav(Func f) const {
        Node* curr = head.get();
        while (curr) {
            f(curr->data);
            curr = curr->next.get();
        }
    }

    std::size_t size() const { return count; }

protected:
    Node* getmaheed() const { return head.get(); }
};
