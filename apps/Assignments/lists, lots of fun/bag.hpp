//outlined in MS copilot
#pragma once
#include "list.hpp"

template<typename T>
class Bag {
private:
    List<T> items;

public:
    void add(const T& item) {
        items.knockback(item);
    }

    bool contains(const T& item) const {
        bool found = false;
        items.trav([&](const T& x){
            if (x == item) found = true;
        });
        return found;
    }

    bool rem(const T& item) {
        return items.rem(item);
    }

    std::size_t size() const {
        return items.size();
    }

    template<typename Func>
    void trav(Func f) const {
        items.trav(f);
    }
};
