// Problem: https://atcoder.jp/contests/abc395/tasks/abc395_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 55;
int n;

void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 看当前点距离上下左右四条边界，哪条最近
            int id = min({i, j, n - i + 1, n - j + 1});
            // 确定奇偶性，从而确定符号
            cout << ((id & 1) ? '#' : '.');
        }
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}