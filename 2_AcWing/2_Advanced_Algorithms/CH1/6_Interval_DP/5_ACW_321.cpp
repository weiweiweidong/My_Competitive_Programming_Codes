// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 15, M = 9;
const double INF = 1e9;

int n, m = 8;  // n表示最后剩下n块矩形，m为棋盘尺寸
int s[M][M];   // 二维前缀和
double f[M][M][M][M][N];
double X;  // 平均值

// 快速求二维前缀和
int get_sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
}

// 计算公式结果
double get(int x1, int y1, int x2, int y2) {
    double sum = get_sum(x1, y1, x2, y2) - X;
    return (double)sum * sum / n;
}

// dp
double dp(int x1, int y1, int x2, int y2, int k) {
    double& v = f[x1][y1][x2][y2][k];
    if (v >= 0)
        return v;
    if (k == 1)
        return v = get(x1, y1, x2, y2);

    v = INF;

    // 横着切
    for (int i = x1; i < x2; i++) {
        // 选上面
        v = min(v, get(x1, y1, i, y2) + dp(i + 1, y1, x2, y2, k - 1));
        // 选下面
        v = min(v, get(i + 1, y1, x2, y2) + dp(x1, y1, i, y2, k - 1));
    }

    // 竖着切
    for (int i = y1; i < y2; i++) {
        // 选上面
        v = min(v, get(x1, y1, x2, i) + dp(x1, i + 1, x2, y2, k - 1));
        // 选下面
        v = min(v, get(x1, i + 1, x2, y2) + dp(x1, y1, x2, i, k - 1));
    }

    return v;
}

void solve() {
    cin >> n;
    // 读入数据，并预处理前缀和
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++) {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }

    // 计算平均值
    X = (double)s[m][m] / n;
    // f 初始化
    memset(f, -1, sizeof f);

    double res = sqrt(dp(1, 1, 8, 8, n));
    printf("%.3lf\n", res);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}