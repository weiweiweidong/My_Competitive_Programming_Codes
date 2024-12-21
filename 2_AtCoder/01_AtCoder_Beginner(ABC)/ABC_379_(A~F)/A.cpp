// Problem: https://atcoder.jp/contests/abc379/tasks/abc379_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;

void solve() {
    cin >> s;
    cout << s[1] << s[2] << s[0] << " " << s[2] << s[0] << s[1] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}