// Problem: https://www.acwing.com/problem/content/900/
// 数字三角形模型
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;
int n, INF = -2e9;
int f[N][N], g[N][N];

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> g[i][j];

    // f数组初始化
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= i + 1; j++)
            f[i][j] = INF;
    f[1][1] = g[1][1];

    // 状态转移
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + g[i][j];

    int res = INF;
    for (int j = 1; j <= n; j++)
        res = max(res, f[n][j]);

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}