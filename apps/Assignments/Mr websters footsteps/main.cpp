//outlined with MS copilot
#include <iostream>
#include <string>

#include "Dictionary.h"

int main()
{
    Dictionary<std::string, int> grades;

    grades.insert("Dave", 95);
    grades.insert("Bob", 88);

    grades["Carl"] = 100;

    std::cout << "Dave: "
              << grades.at("Dave")
              << '\n';

    std::cout << "Bob: "
              << grades["Bob"]
              << '\n';

    std::cout << "Carl: "
              << grades["Carl"]
              << '\n';

    std::cout << "\nSize: "
              << grades.size()
              << '\n';

    grades.erase("Bob");

    std::cout << "Size after erase: "
              << grades.size()
              << '\n';

    List<std::string> keyList = grades.keys();

    std::cout << "\nDictionary Keys:\n";

    for(int i = 0; i < keyList.size(); i++)
    {
        std::cout << keyList[i] << '\n';
    }

    return 0;
}