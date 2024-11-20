// Problem: https://www.acwing.com/problem/content/846/
// 走迷宫：使用STl的queue
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int n, m;
int g[N][N], d[N][N];
queue<PII> q;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void BFS() {
    memset(d, -1, sizeof d);
    d[1][1] = 0;
    q.push({1, 1});

    while (q.size()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int a = now.first + dx[i], b = now.second + dy[i];
            if (a < 1 || a > n || b < 1 || b > m)
                continue;
            if (d[a][b] != -1 || g[a][b] == 1)
                continue;
            q.push({a, b});
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