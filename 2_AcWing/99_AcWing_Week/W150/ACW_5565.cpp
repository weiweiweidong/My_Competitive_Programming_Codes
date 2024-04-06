// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
char grid[N][N];
bool st[N][N];
int cnt, n, m;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void bfs(int x, int y) {
    if (st[x][y] || grid[x][y] == '.')
        return;

    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;
    while (q.size()) {
        auto now = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int a = now.first + dx[i], b = now.second + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m)
                continue;
            if (grid[a][b] == '.' || st[a][b])
                continue;

            st[a][b] = true;
            q.push({a, b});
        }
    }

    cnt++;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            bfs(i, j);

    cout << cnt << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}