// Problem: https://atcoder.jp/contests/abc363/tasks/abc363_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;
    if (n >= 200)
        cout << 300 - n << endl;
    else if (n >= 100)
        cout << 200 - n << endl;
    else
        cout << 100 - n << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}