// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a, b, c;

void solve() {
    cin >> a >> b >> c;
    if (a + b == c || a + c == b || b + c == a || (a == b && b == c))
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