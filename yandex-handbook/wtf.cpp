#include <iostream>
#include <string>

int main() {
    std::string original = "Hello, world!";
    std::string copy = original;
    copy[0] = 'W';

    std::cout << "Original: " << original << std::endl;
    std::cout << "Copy: " << copy << std::endl;

    return 0;
}