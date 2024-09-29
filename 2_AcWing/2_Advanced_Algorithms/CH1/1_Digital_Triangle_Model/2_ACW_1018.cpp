// Problem: https://www.acwing.com/problem/content/1020/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, INF = 1e9;
int n;
int w[N][N];
int f[N][N];

void solve() {
    // 读入数据
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &w[i][j]);

    // DP
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            // 进入第一个格子需要花费的成本
            if (i == 1 && j == 1)
                f[i][j] = w[i][j];
            else {
                f[i][j] = INF;
                // 可以从上面的格子走下来
                if (i > 1)
                    f[i][j] = min(f[i][j], f[i - 1][j] + w[i][j]);
                // 可以从左边的格子走过来
                if (j > 1)
                    f[i][j] = min(f[i][j], f[i][j - 1] + w[i][j]);
            }
        }

    printf("%d\n", f[n][n]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}