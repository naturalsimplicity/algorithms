#include <iostream>
#include <string>

template<typename Container>
void Print(const Container& vec, std::string delimiter)
{
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        if (it != vec.begin()) {
            std::cout << delimiter;
        }
        std::cout << *it;
    }
    std::cout << '\n';
}

int main()
{
    
    std::vector<int> data = {1, 2, 3, 4};
    Print(data, ", ");  // 1, 2, 3, 4
    return 0;
}
