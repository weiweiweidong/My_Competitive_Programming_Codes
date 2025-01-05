// Problem: https://atcoder.jp/contests/abc387/tasks/abc387_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int x;

void solve() {
    cin >> x;

    LL res = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
            if (i * j != x)
                res += 1ll * i * j;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}