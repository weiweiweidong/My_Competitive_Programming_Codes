// Problem: https://www.acwing.com/problem/content/2/
// 01背包问题（原始写法）
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
int n, m;  // n为总物品个数，m为总体积
int f[N][N];
int v[N], w[N];

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];

    // 初始化：f[0][0] = 0 ，但这里默认就是0，所以省略了初始化的步骤
    // dp
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i - 1][j];
            if (j >= v[i])
                f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
        }
    }

    // 求最大值
    int res = 0;
    for (int j = 0; j <= m; j++)
        res = max(res, f[n][j]);

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}