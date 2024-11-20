// Problem: https://www.acwing.com/problem/content/1099/

/*
题目：
求出有几个连通块。
*/

// BFS

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
const int M = N * N;

int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
char g[N][N];
bool st[N][N];
int n, m;

void dfs(int x, int y) {
    queue<PII> q;
    q.push({x, y});
    st[x][y] = true;

    while (q.size()) {
        auto now = q.front();
        q.pop();
        for (int i = 0; i < 8; i++) {
            int xx = now.first + dx[i], yy = now.second + dy[i];

            if (xx < 1 || xx > n || yy < 1 || yy > m)
                continue;
            if (st[xx][yy] || g[xx][yy] == '.')
                continue;

            q.push({xx, yy});
            st[xx][yy] = true;
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> (g[i] + 1);

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == 'W' && !st[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }

    cout << cnt << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}