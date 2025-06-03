#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <unordered_set>

using namespace std;


int IsPalindrome(int time)
{
    int hours = time / 60;
    int minutes = time % 60;
    if (hours / 10 == minutes % 10 && hours % 10 == minutes / 10) {
        return 1;
    }
    return 0;
}

int CountPalindromes(int start_time, int interval)
{
    unordered_set<int> seen;
    unordered_set<int> palindromes;
 
    int cur_time = start_time;
    while (seen.find(cur_time) == seen.end()) {
        seen.insert(cur_time);
        if (IsPalindrome(cur_time)) {
            palindromes.insert(cur_time);
        }
        cur_time = (cur_time + interval) % (60 * 24);
    }
    
    return palindromes.size();
}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int hours, minutes, interval;
        sscanf(s.data(), "%d:%d", &hours, &minutes);
        cin >> interval;
        cout << CountPalindromes(hours * 60 + minutes, interval) << '\n';
    }

    return 0;
}
