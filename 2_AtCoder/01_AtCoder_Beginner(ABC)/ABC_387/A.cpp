// Problem: https://atcoder.jp/contests/abc387/tasks/abc387_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a, b;

void solve() {
    cin >> a >> b;
    cout << (a + b) * (a + b) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}