// Problem: https://www.acwing.com/problem/content/description/177/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

#define x first
#define y second

const int N = 510, M = N * N;
int n, m;
char g[N][N];
int dist[N][N];
bool st[N][N];

int bfs() {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0][0] = 0;
    deque<PII> q;  // 双端队列
    q.push_back({0, 0});

    char cs[] = "\\/\\/";  // "\" 符号需要转义。cs 直接打印出来是：\/\/
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};  // 点的方向
    int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};  // 格子的方向

    while (q.size()) {
        PII now = q.front();  // 从前面取
        q.pop_front();

        if (st[now.x][now.y])
            continue;
        st[now.x][now.y] = true;

        for (int i = 0; i < 4; i++) {
            // 计算点的坐标
            int next_x = now.x + dx[i], next_y = now.y + dy[i];
            if (next_x < 0 || next_x > n || next_y < 0 || next_y > m)
                continue;
            // 计算格子的坐标
            int ca = now.x + ix[i], cb = now.y + iy[i];
            // 判断这条边的长度是 0 还是 1
            int d = dist[now.x][now.y] + (g[ca][cb] != cs[i]);

            // 模仿 dijkstra，更新 dist
            if (d < dist[next_x][next_y]) {
                dist[next_x][next_y] = d;

                // 如果没有边，就从后面插入
                if (g[ca][cb] != cs[i])
                    q.push_back({next_x, next_y});
                // 如果有边，就从前面插入
                else
                    q.push_front({next_x, next_y});
            }
        }
    }

    return dist[n][m];
}

void solve() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> g[i];

        int res = bfs();

        if (res == 0x3f3f3f3f)
            cout << "NO SOLUTION" << endl;
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