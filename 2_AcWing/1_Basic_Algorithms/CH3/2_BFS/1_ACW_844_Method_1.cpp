// Problem: https://www.acwing.com/problem/content/846/
// 走迷宫：数组模拟queue
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int n, m;
int g[N][N], d[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
PII q[N * N];
int hh, tt;

void BFS() {
    memset(d, -1, sizeof d);
    hh = 0, tt = 0;
    q[0] = {1, 1};
    d[1][1] = 0;

    while (hh <= tt) {
        auto now = q[hh++];
        for (int i = 0; i < 4; i++) {
            int a = now.first + dx[i], b = now.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
                continue;
            if (d[a][b] != -1 || g[a][b] == 1)
                continue;
            q[++tt] = {a, b};
            d[a][b] = d[now.first][now.second] + 1;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];
    BFS();
    cout << d[n][m] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}