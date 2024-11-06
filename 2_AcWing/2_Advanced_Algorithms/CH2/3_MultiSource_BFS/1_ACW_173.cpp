// Problem: https://www.acwing.com/problem/content/175/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
int g[N][N];
int dist[N][N];
int n, m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void solve() {
    // 读入数据s
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            char x;
            cin >> x;
            g[i][j] = (x == '1');
        }

    // 找出所有的 1 点，把坐标存入队列
    memset(dist, -1, sizeof dist);
    queue<PII> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j]) {
                q.push({i, j});
                dist[i][j] = 0;
            }

    // BFS
    while (q.size()) {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int xx = now.first + dx[i], yy = now.second + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > m)
                continue;
            if (dist[xx][yy] != -1)
                continue;

            dist[xx][yy] = dist[now.first][now.second] + 1;
            q.push({xx, yy});
        }
    }

    // 输出结果
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << dist[i][j] << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}