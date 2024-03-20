// Problem: https://www.acwing.com/problem/content/902/
// 整数划分：使用另一种DP思路
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010, MOD = 1e9 + 7;
int n;
int f[N][N];

void solve() {
    cin >> n;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = (f[i - 1][j - 1] + f[i - j][j]) % MOD;

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = (res + f[n][i]) % MOD;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}