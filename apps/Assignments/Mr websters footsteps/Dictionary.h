//outlines with MS copilot
#pragma once

#include "Pair.h"
#include "Tree.hpp"
#include "list.hpp"

#include <stdexcept>

template<typename Key, typename Value>
class Dictionary
{
private:

    AVLTree<Pair<Key, Value>> tree;

    void collectKeys(
        typename AVLTree<Pair<Key,Value>>::Node* node,
        List<Key>& result) const
    {
        if(node == nullptr)
            return;

        collectKeys(node->left, result);

        result.push_back(node->data.first);

        collectKeys(node->right, result);
    }

    void collectValues(
        typename AVLTree<Pair<Key,Value>>::Node* node,
        List<Value>& result) const
    {
        if(node == nullptr)
            return;

        collectValues(node->left, result);

        result.push_back(node->data.second);

        collectValues(node->right, result);
    }

public:

    Dictionary() = default;

    ~Dictionary() = default;

    Dictionary(const Dictionary&) = default;

    Dictionary& operator=(const Dictionary&) = default;

    Dictionary(Dictionary&&) noexcept = default;

    Dictionary& operator=(Dictionary&&) noexcept = default;

    Value& operator[](const Key& key)
    {
        Pair<Key, Value> temp{key, Value{}};

        auto* node = tree.find(temp);

        if(node == nullptr)
        {
            tree.insert(temp);
            node = tree.find(temp);
        }

        return node->data.second;
    }

    Value& at(const Key& key)
    {
        Pair<Key, Value> temp{key, Value{}};

        auto* node = tree.find(temp);

        if(node == nullptr)
        {
            throw std::out_of_range("Key not found.");
        }

        return node->data.second;
    }

    const Value& at(const Key& key) const
    {
        Pair<Key, Value> temp{key, Value{}};

        auto* node = tree.find(temp);

        if(node == nullptr)
        {
            throw std::out_of_range("Key not found.");
        }

        return node->data.second;
    }

    void insert(const Key& key, const Value& value)
    {
        tree.insert({key, value});
    }

    void erase(const Key& key)
    {
        tree.erase({key, Value{}});
    }

    void clear()
    {
        tree.clear();
    }

    List<Key> keys() const
    {
        List<Key> result;

        collectKeys(tree.getRoot(), result);

        return result;
    }


    List<Value> values() const
    {
        List<Value> result;

        collectValues(tree.getRoot(), result);

        return result;
    }

    bool isEmpty() const
    {
        return tree.isEmpty();
    }

    std::size_t size() const
    {
        return tree.size();
    }
};