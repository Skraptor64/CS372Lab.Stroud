//outlined in MS copilot, I was unable to find the source codes referenced in the NOTE,
//this is likely due to my own problems rather than a lack of source codes.
#pragma once
#include "Tree.hpp"

template<typename T>
typename Tree<T>::Node* prune_copy(
    typename Tree<T>::Node* original,
    typename Tree<T>::Node* parent)
{
    if (!original) return nullptr;

    if (original->children.empty()) {
        return nullptr;
    }

    auto* newNode = new typename Tree<T>::Node(original->data, parent);

    for (auto& child : original->children) {
        auto* c = prune_copy<T>(child.get(), newNode);
        if (c) {
            newNode->children.emplace_back(c);
        }
    }

    return newNode;
}

template<typename T>
Tree<T> prune(const Tree<T>& original)
{
    Tree<T> pruned;

    if (original.root) {
        pruned.root.reset(prune_copy<T>(original.root.get(), nullptr));
    }

    return pruned;
}
