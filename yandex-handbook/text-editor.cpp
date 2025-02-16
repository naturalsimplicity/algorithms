#include <iostream>
#include <string>
#include <list>

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& a)
{
    for (const T& x : a) {
        out << x << '\n';
    }
    return out;
}


int main()
{
    std::list<std::string> data;
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        if (line.empty()) {
            break;
        }
        data.push_back(line);
    }
    std::string buffer;
    auto iter = data.begin();
    std::string command;
    while (std::cin >> command) {
        // std::getline(std::cin, command);
        if (command.empty()) {
            break;
        }
        if (command == "Down") {
            if (iter == data.end()) {
                continue;
            }
            ++iter;
        } else if (command == "Up") {
            if (iter == data.begin()) {
                continue;
            }
            --iter;
        } else if (command == "Ctrl+X") {
            if (iter == data.end()) {
                continue;
            }
            buffer = std::move(*iter);
            iter = data.erase(iter);
        } else if (command == "Ctrl+V") {
            if (buffer.empty()) {
                continue;
            }
            data.insert(iter, buffer);
        }
    }
    std::cout << data;

    return 0;
}