//outlined in MS copilot
#include <iostream>
#include "list.hpp"
#include "circlelist.hpp"
#include "bag.hpp"

int main() {

    std::cout << "=== Testing List<T> ===\n";
    List<int> a;
    a.knockback(10);
    a.knockback(20);
    a.knockback(30);

    std::cout << "Original list: ";
    a.trav([](int x){ std::cout << x << " "; });
    std::cout << "\n";

    std::cout << "Copy constructing b from a...\n";
    List<int> b = a;

    std::cout << "b: ";
    b.trav([](int x){ std::cout << x << " "; });
    std::cout << "\n";

    std::cout << "Move constructing c from a...\n";
    List<int> c = std::move(a);

    std::cout << "c: ";
    c.trav([](int x){ std::cout << x << " "; });
    std::cout << "\n";

    std::cout << "a (after move): ";
    a.trav([](int x){ std::cout << x << " "; });
    std::cout << "\n";

    std::cout << "\n=== Testing Bag ===\n";
    Bag<std::string> bag;
    bag.add("apple");
    bag.add("banana");
    bag.add("apple");

    std::cout << "Bag contains apple? " << (bag.contains("apple") ? "yes" : "no") << "\n";
    std::cout << "Bag size: " << bag.size() << "\n";

    std::cout << "Bag items: ";
    bag.trav([](const std::string& s){ std::cout << s << " "; });
    std::cout << "\n";

    std::cout << "Removing apple...\n";
    bag.rem("apple");

    std::cout << "Bag items: ";
    bag.trav([](const std::string& s){ std::cout << s << " "; });
    std::cout << "\n";

    std::cout << "\n=== Testing Circle List ===\n";
    circlelist<int> cl;
    cl.knockback(1);
    cl.knockback(2);
    cl.knockback(3);
    cl.knockback(4);

    std::cout << "Circular traversal starting at index 2: ";
    cl.cycle(2, [](int x){ std::cout << x << " "; });
    std::cout << "\n";

    return 0;
}
