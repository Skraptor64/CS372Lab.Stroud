//code outlined with MS copilot
#ifndef RECEIPTBAG_H
#define RECEIPTBAG_H

#include <vector>
#include <stdexcept>

template <typename T>
class ReceiptBag {
private:
    std::vector<T> items;        // these lines store an item
    std::vector<int> receipts;   // and a matching receipt
    int next;             // this line generates the next receipt number

public:
    ReceiptBag() : next(1) {}

    // this part of the function is for inserting an item into the bag
    // while returning the unique reciept number.
    int insert(const T& item) {
        items.push_back(item);
        receipts.push_back(next);
        return next++;
    }

    // this part is for removing an item
    // by using the reciept number and returning the item that was removed.
    T remove(int receipt) {
        for (size_t i = 0; i < receipts.size(); i++) {
            if (receipts[i] == receipt) {
                T rem = items[i];

                // this makes sure both vectors are properly
                // cleaned up after the item is removed.
                items.erase(items.begin() + i);
                receipts.erase(receipts.begin() + i);

                return rem;
            }
        }
         // if the reciept number is invalid, this will scream at you (throw an exception).
        throw std::runtime_error("I've been looking for you everywhere - except where you were. \n[Item not found]");
    }

    size_t size() const { return items.size(); }
    bool empty() const { return items.empty(); }
};

#endif
