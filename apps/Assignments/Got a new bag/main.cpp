//code outlined with MS copilot
#include <iostream>
#include "ReceiptBag.h"

int main() {
    ReceiptBag<std::string> bag;

    // This inserts some items into the bag
    int r1 = bag.insert("apple");
    int r2 = bag.insert("banana");
    int r3 = bag.insert("apple"); 

    // This will display the receipts for the inserted items
    std::cout << "Inserted apple and got a receipt " << r1 << "\n";
    std::cout << "Inserted banana and got a receipt " << r2 << "\n";
    std::cout << "Inserted apple and got a receipt " << r3 << "\n";

    // This removes just one item using the receipt and displays how many items are
    // left in the bag
    std::cout << "\nRemoving item " << r2 << "...\n";
    std::string removed = bag.remove(r2);
    std::cout << "Removed item: " << removed << "\n";

    std::cout << "\nYour bundle now holds " << bag.size() << "/64 items.\n";

    // This bit tries to remove an item with an invalid receipt and gives the code
    // an aneurysm. Do not be alarmed, this code is trained for this.
    // In English: It will throw an exception, catch it and display the proper error message.
    try {
        std::cout << "\nRemoving item 999...\n";
        bag.remove(999);
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << "\n";
    }

    return 0;
}
