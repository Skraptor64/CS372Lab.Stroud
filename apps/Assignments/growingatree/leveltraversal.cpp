//outlined with MS copilot, I was unable to find the source codes referenced in the NOTE
//this is likely due to my own problems rather than a lack of source codes.
#include <queue>
#include <functional>
#include "Tree.hpp"

template<typename T>
void level_trav(const Tree<T>& tree, std::function<void(const T&)> visit) {
    if (!tree.root) return;

    std::queue<typename Tree<T>::Node*> q;
    q.push(tree.root.get());

    std::function<void()> process = [&]() {
        if (q.empty()) return;

        typename Tree<T>::Node* node = q.front();
        q.pop();

        visit(node->data);

        for (auto& child : node->children) {
            q.push(child.get());
        }

        process();
    };

    process();
}
