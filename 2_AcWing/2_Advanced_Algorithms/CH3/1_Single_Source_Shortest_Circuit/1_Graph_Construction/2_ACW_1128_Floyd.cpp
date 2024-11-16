// Problem: https://www.acwing.com/problem/content/1130/

// Floyd 算法，使用邻接矩阵构建图
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, INF = 0x3f3f3f3f;
int n, m;
int dist[N][N];

void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void solve() {
    cin >> n >> m;
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }

    floyd();

    int res = 0;
    for (int i = 1; i <= n; i++)
        if (dist[1][i] == INF) {
            res = -1;
            break;
        } else
            res = max(res, dist[1][i]);

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}