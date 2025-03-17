// Problem: https://atcoder.jp/contests/abc397/tasks/abc397_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;
void solve() {
    cin >> s;
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'i' && i + 1 < s.size() && s[i + 1] == 'o') {
            i++;
            continue;
        }
        res += 1;
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}