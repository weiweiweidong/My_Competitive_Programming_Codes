// Problem: https://atcoder.jp/contests/abc377/tasks/abc377_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;

void solve() {
    cin >> s;
    sort(s.begin(), s.end());
    if (s == "ABC")
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}