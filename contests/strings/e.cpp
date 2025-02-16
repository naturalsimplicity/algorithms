#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() 
{
    string s1, s2, heap;
    cin >> s1 >> s2 >> heap;

    string heap_src = s1 + s2;

    sort(heap_src.begin(), heap_src.end());
    sort(heap.begin(), heap.end());

    if (heap == heap_src) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    cout << '\n';

    return 0;
}