// Problem: https://www.acwing.com/problem/content/798/
// 二维前缀和
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
int grid[N][N], s[N][N];
int n, m, q;

void solve() {
    // 读入数据
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
            // 预处理前缀和
            s[i][j] = grid[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    while (q--) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        // 计算子矩阵内部元素和
        int res = s[x][y] - s[a - 1][y] - s[x][b - 1] + s[a - 1][b - 1];
        cout << res << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}