#include <iostream>
#include <vector>

using namespace std;

template<typename T>
ostream& operator<<(ostream& out, const vector<T>& a)
{
    for (const T& x : a) {
        out << x << ' ';
    }
    return out;
}

void Partition(int l, int r, int x, vector<int>& a, int &i, int &j) {
    // сортируем a[l..r]
    // i, j - это границы равных элементов (из x)
    i = l, j = r;
    while (i <= j) {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j) swap(a[i++], a[j--]);
    }
}

int main()
{
    vector<int> v1 {3, 5, 1, 2, 7, 9, 4, 5};
    int i = 0, j = 0;
    Partition(0, 7, 5, v1, i, j);
    cout << v1 << '\n';
    cout << i << ", " << j << '\n';


    return 0;
}