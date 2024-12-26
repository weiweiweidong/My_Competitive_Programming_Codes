// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_c

// DP
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3010;
int a[N];
int f[N][N];
int n, res;

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // dp 数组初始化
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = 1;

    // f[i][j] 表示：以第i个位置结尾，且前后两个相同数字距离是j时，最大长度
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i - j >= 1 && a[i] == a[i - j])
                f[i][j] = max(f[i][j], f[i - j][j] + 1);
            res = max(res, f[i][j]);
        }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}