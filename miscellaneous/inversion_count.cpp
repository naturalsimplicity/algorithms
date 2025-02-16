/*
Given an integer array arr[] of size n, find the inversion count in the array.
Two array elements arr[i] and arr[j] form an inversion if arr[i] > arr[j] and i < j.

Note: Inversion Count for an array indicates that how far (or close)
the array is from being sorted. If the array is already sorted, 
then the inversion count is 0, but if the array is sorted in reverse order,
the inversion count is maximum. 
*/

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


int Merge(vector<int>& arr, int ls, int medium, int re)
{
    int n = medium - ls, m = re - medium;
    int inversions = 0;
    vector<int> left(n), right(m);
    copy(arr.begin() + ls, arr.begin() + medium, left.begin());
    copy(arr.begin() + medium, arr.begin() + re, right.begin());
    int i = 0, j = 0, k = 0;
    while (i < n && i < m) {
        if (left[i] <= right[j]) {
            arr[ls + k++] = left[i++];
        } else {
            arr[ls + k++] = right[j++];
            inversions += n - i;
        }
    }
    while (i < n) {
        arr[ls + k++] = left[i++];
    }
    while (j < n) {
        arr[ls + k++] = right[j++];
    }
    return inversions;
}

int MergeSort(vector<int>& arr, int l, int r) {
    // sort arr [l, r)
    if (r - l == 1) {
        return 0;
    } else {
        int inversions = 0;
        int m = (r + l) / 2;
        inversions += MergeSort(arr, l, m);
        inversions += MergeSort(arr, m, r);
        inversions += Merge(arr, l, m, r);
        return inversions;
    }
}

int main()
{
    vector<int> v1 {1, 3, 4, 5, 2, 4, 6, 7};
    // vector<int> v2 {2, 3, 4, 5};
    // cout << Merge(v1, v2) << '\n';
    // MergeSort(v1, 0, v1.size());
    int inv = MergeSort(v1, 0, v1.size());
    cout << inv << '\n';
    cout << v1 << '\n';
    return 0;
}