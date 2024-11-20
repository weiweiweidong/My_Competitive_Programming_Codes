// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10, MOD = 1e9 + 7;
int x, y;
int f[N];

void solve() {
    cin >> x >> y;
    int h = 0;
    // 预处理最大值h
    while ((h + 1) * (h + 2) / 2 <= x + y)
        h++;

    // 预处理f数组
    f[0] = 1;
    for (int i = 1; i <= h; i++)
        for (int j = x; j >= i; j--)
            f[j] = (f[j] + f[j - i]) % MOD;

    int res = 0;
    // 计算方案数
    for (int i = max(0, h * (h + 1) / 2 - y); i <= x; i++)
        res = (res + f[i]) % MOD;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}