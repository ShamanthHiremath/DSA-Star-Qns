#include <iostream>
#include <map>

int main() {
    std::map<int, std::string> myMap = {{1, "Apple"}, {2, "Banana"}, {3, "Cherry"}};

    // Defining an iterator
    std::map<int, std::string>::iterator it;

    // Iterating through the map
    for (it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << it->first << " -> " << it->second << std::endl;
    }

    return 0;
}