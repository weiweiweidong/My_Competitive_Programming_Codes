// Problem: https://www.acwing.com/problem/content/856/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 210, INF = 1e9;
int n, m, Q;
int d[N][N];

void floyd() {
    for (int k = 1; k <= n; k++)                            // 遍历中间点
        for (int i = 1; i <= n; i++)                        // 遍历起点
            for (int j = 1; j <= n; j++)                    // 遍历终点
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);  // 更新
}

void solve() {
    cin >> n >> m >> Q;
    // 初始化距离矩阵 d
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }
    // 读入边，使用邻接矩阵存储
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = min(d[a][b], c);
    }

    floyd();

    // 输出结果
    while (Q--) {
        int a, b;
        cin >> a >> b;
        int res = d[a][b];
        if (res > INF / 2)
            cout << "impossible" << endl;
        else
            cout << res << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}