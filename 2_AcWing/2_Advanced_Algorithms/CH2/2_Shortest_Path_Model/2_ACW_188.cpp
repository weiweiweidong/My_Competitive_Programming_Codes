// Problem: https://www.acwing.com/problem/content/190/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 160;
char g[N][N];
int dist[N][N];
int R, C;
// 日字形跳跃
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
PII st, ed;

void bfs(int x, int y) {
    queue<PII> q;
    q.push({x, y});
    dist[x][y] = 0;

    while (q.size()) {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int xx = now.first + dx[i], yy = now.second + dy[i];
            if (xx < 1 || yy < 1 || xx > R || yy > C)
                continue;
            if (g[xx][yy] == '*' || dist[xx][yy] != -1)
                continue;
            q.push({xx, yy});
            dist[xx][yy] = dist[now.first][now.second] + 1;

            if (g[xx][yy] == 'H')
                return;
        }
    }
}

void solve() {
    // 读入数据
    cin >> C >> R;
    for (int i = 1; i <= R; i++)
        cin >> (g[i] + 1);

    // 找到起点和终点
    for (int i = 1; i <= R; i++)
        for (int j = 1; j <= C; j++) {
            if (g[i][j] == 'K')
                st = {i, j};
            if (g[i][j] == 'H')
                ed = {i, j};
        }

    memset(dist, -1, sizeof dist);
    bfs(st.first, st.second);

    // 输出结果
    cout << dist[ed.first][ed.second] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}