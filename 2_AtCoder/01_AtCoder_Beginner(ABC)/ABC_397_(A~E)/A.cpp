// Problem: https://atcoder.jp/contests/abc397/tasks/abc397_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    double a;
    cin >> a;
    if (a >= 38.0)
        cout << 1 << endl;
    else if (a < 37.5)
        cout << 3 << endl;
    else
        cout << 2 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}