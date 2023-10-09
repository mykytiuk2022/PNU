#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main() {
    std::set<int> set1 = { 1, 3, 5, 7 };
    std::set<int> set2 = { 2, 4, 5, 6 };

    std::set<int> result(set1.size() + set2.size()); // Створюємо вектор для збереження результату
    auto it = std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), result.begin());

    result.resize(it - result.begin()); // Зменшуємо розмір вектору до розміру результату

    for (const auto& elem : result) {
        std::cout << elem << " ";
    }

    return 0;
}
