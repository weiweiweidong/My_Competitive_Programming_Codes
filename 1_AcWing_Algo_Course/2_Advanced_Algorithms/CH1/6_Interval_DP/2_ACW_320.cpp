// Problem: https://www.acwing.com/problem/content/322/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 220, INF = 0x3f3f3f3f;
int n;
int w[N];
int f[N][N];

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
        // 破环成链
        w[i + n] = w[i];
    }

    // 第一层循环：遍历区间长度
    for (int len = 3; len <= n + 1; len++) {
        // 第二层循环：遍历起始点
        for (int l = 1; l + len - 1 <= n * 2; l++) {
            int r = l + len - 1;
            // 第三层循环：遍历分界点
            for (int k = l + 1; k < r; k++)
                f[l][r] = max(f[l][r], f[l][k] + f[k][r] + w[l] * w[k] * w[r]);
        }
    }

    // 找最值
    int res = 0;
    for (int l = 1; l <= n; l++)
        res = max(res, f[l][l + n]);
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}