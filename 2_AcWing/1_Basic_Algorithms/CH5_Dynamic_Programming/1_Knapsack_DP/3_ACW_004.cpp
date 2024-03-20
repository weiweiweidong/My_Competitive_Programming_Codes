// Problem: https://www.acwing.com/problem/content/4/
// 多重背包问题最朴素写法，时间复杂度 O(n^3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int n, m;
int f[N][N];
int v[N], w[N], s[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - v[i] * k] + w[i] * k);
        }
    }
    cout << f[n][m] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}