#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    string file;
    cin >> n >> file;
    
    int cnt = 0, cnt_to_delete = 0;
    for (int i = 0; i < n; ++i) {
        if (file[i] == 'x') {
            ++cnt;
            if (i == n-1 && cnt > 2) {
                cnt_to_delete += cnt - 2;
            }
        } else {
            if (cnt > 2) {
                cnt_to_delete += cnt - 2;
            }
            cnt = 0;
        }
    }
    cout << cnt_to_delete << '\n';

    return 0;
}