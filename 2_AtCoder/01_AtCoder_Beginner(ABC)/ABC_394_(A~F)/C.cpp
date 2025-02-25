// Problem: https://atcoder.jp/contests/abc394/tasks/abc394_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;

// 从前往后做法
void solve() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        int right = i;
        if (s[i] == 'W') {
            while (right + 1 < s.size() && s[right + 1] == 'W')
                right++;
            if (right + 1 < s.size() && s[right + 1] == 'A') {
                string tmp = "A" + string(right + 1 - (i + 1) + 1, 'C');
                s.replace(i, right + 1 - i + 1, tmp);
            }
            i = right;
        }
    }
    cout << s << endl;
}

// 从后往前做法
void solve2() {
    cin >> s;
    int n = s.size();
    s = " " + s;

    for (int i = n; i > 1; i--) {
        if (s[i - 1] == 'W' && s[i] == 'A')
            s[i - 1] = 'A', s[i] = 'C';
    }

    cout << s.substr(1) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve2();
    return 0;
}