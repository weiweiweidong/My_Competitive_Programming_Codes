// Problem: https://atcoder.jp/contests/abc378/tasks/abc378_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int f[4];

void solve() {
    for (int i = 0; i < 4; i++) {
        int c;
        cin >> c;
        f[c]++;
    }

    int res = 0;
    for (int i = 1; i <= 4; i++)
        res += f[i] / 2;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}