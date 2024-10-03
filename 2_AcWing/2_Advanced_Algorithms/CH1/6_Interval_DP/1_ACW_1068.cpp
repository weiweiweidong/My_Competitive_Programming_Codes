// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 420, INF = 0x3f3f3f3f;
int n;
int s[N], w[N];        // s 存前缀和，w 存权重
int f[N][N], g[N][N];  // f 存最小值，g 存最大值

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        w[n + i] = w[i];
    }

    // 预处理前缀和
    for (int i = 1; i <= 2 * n; i++)
        s[i] = s[i - 1] + w[i];

    memset(f, 0x3f, sizeof f);
    memset(g, -0x3f, sizeof g);

    // 第一层循环：遍历区间长度
    for (int len = 1; len <= n; len++)
        // 第二层循环：遍历起始点
        for (int l = 1; l + len - 1 <= 2 * n; l++) {
            int r = l + len - 1;

            if (len == 1)
                f[l][r] = g[l][r] = 0;
            else {
                // 第三层循环：遍历分界点
                for (int k = l; k < r; k++) {
                    f[l][r] =
                        min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                    g[l][r] =
                        max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
                }
            }
        }

    int min_v = INF, max_v = -INF;
    for (int i = 1; i <= n; i++) {
        min_v = min(min_v, f[i][i + n - 1]);
        max_v = max(max_v, g[i][i + n - 1]);
    }

    cout << min_v << endl;
    cout << max_v << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}