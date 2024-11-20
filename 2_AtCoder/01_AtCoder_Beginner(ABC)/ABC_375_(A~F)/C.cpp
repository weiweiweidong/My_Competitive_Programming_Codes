// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3010;
char g[N][N];
char res[N][N];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> g[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            // 计算 (i,j) 在从外向第几层上
            int times = min(min(i + 1, j + 1), min(n - i, n - j));
            times %= 4;

            // 顺时针旋转 360 度（不动）
            if (times == 0)
                res[i][j] = g[i][j];
            // 顺时针旋转 90 度
            if (times == 1)
                res[i][j] = g[n - j - 1][i];
            // 顺时针旋转 180 度
            if (times == 2)
                res[i][j] = g[n - i - 1][n - j - 1];
            // 顺时针旋转 270 度
            if (times == 3)
                res[i][j] = g[j][n - i - 1];
        }

    // 输出结果
    for (int i = 0; i < n; i++) {
        cout << res[i] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}