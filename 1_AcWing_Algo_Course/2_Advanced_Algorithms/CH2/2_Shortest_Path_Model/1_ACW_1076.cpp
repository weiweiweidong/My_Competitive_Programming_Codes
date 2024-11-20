// Problem: https://www.acwing.com/problem/content/1078/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

const int N = 1010;
int g[N][N];
PII pre[N][N];
int dist[N][N];
int n;

void bfs(int x, int y) {
    queue<PII> q;
    q.push({x, y});
    memset(dist, 0x3f, sizeof dist);
    dist[x][y] = 0;

    while (q.size()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int xx = now.first + dx[i], yy = now.second + dy[i];
            if (xx < 1 || yy < 1 || xx > n || yy > n)
                continue;
            if (g[xx][yy])
                continue;
            if (dist[xx][yy] != 0x3f3f3f3f)
                continue;

            q.push({xx, yy});
            pre[xx][yy] = {now.first, now.second};  // 用于存储上一个点
            dist[xx][yy] = dist[now.first][now.second] + 1;  // 用于输出距离
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> g[i][j];

    // 从后往前开始找
    bfs(n, n);

    // 正向开始输出路径
    PII end = {1, 1};
    while (true) {
        cout << end.first - 1 << " " << end.second - 1 << endl;
        if (end.first == n && end.second == n)
            break;
        end = pre[end.first][end.second];
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}