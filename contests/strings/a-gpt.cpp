#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Функция для подсчета пары "ab" или "ba" в строке
int countSubstring(const string& s, const string& pattern) {
    int count = 0;
    for (size_t i = 0; i + 1 < s.size(); ++i) {
        if (s.substr(i, 2) == pattern) {
            ++count;
        }
    }
    return count;
}

int main() {
    int q;
    cin >> q; // Количество тестовых наборов
    vector<string> results; // Сохраняем результаты для всех наборов данных

    while (q--) {
        string t;
        cin >> t;

        // Подсчитаем количество "ab" и "ba"
        int countAB = countSubstring(t, "ab");
        int countBA = countSubstring(t, "ba");

        // Если количество уже равно, добавляем как есть
        if (countAB == countBA) {
            results.push_back(t);
            continue;
        }

        // Если не равно, изменяем ровно 1 символ
        // Простой способ решения:
        // Меняем любой символ в первой паре, порождающей дисбаланс
        bool adjusted = false;
        for (size_t i = 0; i + 1 < t.size(); ++i) {
            if (!adjusted && ((countAB > countBA && t.substr(i, 2) == "ab") ||
                              (countBA > countAB && t.substr(i, 2) == "ba"))) {
                t[i] = (t[i] == 'a' ? 'b' : 'a'); // Меняем символ
                adjusted = true;
                break;
            }
        }

        // Добавляем исправленную строку
        results.push_back(t);
    }

    // Вывод всех ответов
    for (const string& res : results) {
        cout << res << endl;
    }

    return 0;
}