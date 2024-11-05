// Problem: https://www.acwing.com/problem/content/1100/

// BFS
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};

const int N = 60;
int n, m;
int g[N][N];
bool st[N][N];
int cnt, max_area;

void bfs(int x, int y) {
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    int area = 0;

    while (q.size()) {
        auto t = q.front();
        q.pop();
        area++;  // 出队的时候统计面积
        for (int i = 0; i < 4; i++) {
            int xx = t.first + dx[i], yy = t.second + dy[i];
            if (xx < 1 || y < 1 || xx > n || yy > m)
                continue;
            if (st[xx][yy])
                continue;
            if (g[t.first][t.second] >> i & 1)
                continue;
            q.push({xx, yy});
            st[xx][yy] = true;
        }
    }
    max_area = max(max_area, area);
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> g[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (!st[i][j]) {
                bfs(i, j);
                cnt++;
            }
    cout << cnt << endl;
    cout << max_area << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}