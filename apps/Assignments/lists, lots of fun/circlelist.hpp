//outlined in MS copilot
#pragma once
#include "list.hpp"

template<typename T>
class circlelist : public List<T> {
public:
    template<typename Func>
    void cycle(std::size_t startIndex, Func f) const {
        if (this->size() == 0) return;

        auto* curr = this->getmaheed();

        for (std::size_t i = 0; i < startIndex; i++) {
            curr = curr->next ? curr->next : this->getmaheed();
        }

        auto* start = curr;

        do {
            f(curr->data);
            curr = curr->next ? curr->next : this->getmaheed();
        } while (curr != start);
    }
};
