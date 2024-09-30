// Problem: https://www.acwing.com/problem/content/1059/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, K = 110;
int n, k;
int w[N];
int f[N][K][2];

void solve() {
    // 输入数据
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    // f 初始化为负无穷。（因为有可能因为买股票亏损导致负数）
    memset(f, -0x3f, sizeof f);
    for (int i = 0; i <= n; i++)
        f[i][0][0] = 0;  // 0交易未持有 都赋值为 0

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= k; j++) {
            // 当前天为 未持有 状态
            f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + w[i]);
            // 当前天为 持有 状态
            f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - w[i]);
        }

    // 求出最大值
    int res = 0;
    for (int i = 0; i <= k; i++)
        res = max(res, f[n][i][0]);

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}