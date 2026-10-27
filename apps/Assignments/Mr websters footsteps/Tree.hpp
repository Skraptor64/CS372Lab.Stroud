//outlined with MS copilot
#pragma once
#include <memory>
#include <vector>
#include <utility>

template<typename T>
class Tree {
public:
    struct Node {
        T data;
        Node* parent;
        std::vector<std::unique_ptr<Node>> children;

        Node(const T& d, Node* p = nullptr)
            : data(d), parent(p) {}
    };

    std::unique_ptr<Node> root;

public:
    Tree() : root(nullptr) {}

    Tree(const T& rootValue) {
        root = std::make_unique<Node>(rootValue, nullptr);
    }

    Tree(const Tree& other) {
        if (other.root) {
            root = copy_subtree(other.root.get(), nullptr);
        }
    }

    Tree& operator=(const Tree& other) {
        if (this != &other) {
            root.reset();
            if (other.root) {
                root = copy_subtree(other.root.get(), nullptr);
            }
        }
        return *this;
    }

    Tree(Tree&& other) noexcept
        : root(std::move(other.root)) {}

    Tree& operator=(Tree&& other) noexcept {
        if (this != &other) {
            root = std::move(other.root);
        }
        return *this;
    }

    Node* add_child(Node* parent, const T& value) {
        if (!parent) return nullptr;

        parent->children.push_back(
            std::make_unique<Node>(value, parent)
        );

        return parent->children.back().get();
    }

    Node* set_root(const T& value) {
        root = std::make_unique<Node>(value, nullptr);
        return root.get();
    }

private:
    Node* copy_subtree(Node* original, Node* parent) {
        if (!original) return nullptr;

        Node* newNode = new Node(original->data, parent);

        for (auto& child : original->children) {
            Node* copiedChild = copy_subtree(child.get(), newNode);
            if (copiedChild) {
                newNode->children.emplace_back(copiedChild);
            }
        }

        return newNode;
    }
};
