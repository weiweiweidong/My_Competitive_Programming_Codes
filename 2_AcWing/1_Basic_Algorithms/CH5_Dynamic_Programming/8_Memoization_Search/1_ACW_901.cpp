// Problem: https://www.acwing.com/problem/content/903/
// 记忆化搜索
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 310;
int n, m;
int g[N][N];
int f[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dp(int x, int y) {
    int& v = f[x][y];

    // 说明已经计算过了
    if (v != -1)
        return v;

    // 初始值给1
    v = 1;
    // 看一下四个方向
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 1 || a > n || b < 1 || b > m)
            continue;
        if (g[x][y] <= g[a][b])
            continue;
        v = max(v, dp(a, b) + 1);
    }
    return v;
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    // 初始化（表示每一个状态都没有被算过）
    memset(f, -1, sizeof f);

    // 枚举每一个起点，并更新最大值
    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res = max(res, dp(i, j));

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}