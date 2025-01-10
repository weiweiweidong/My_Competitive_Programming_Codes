// Problem: https://atcoder.jp/contests/abc387/tasks/abc387_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;

char g[N][N];      // 存储网格
bool st[N][N][2];  // 存储每个点的遍历状态
int dis[N][N][2];  // 存储每个点的距离
int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};  // 按照 左右上下 的方向
struct Node {
    int x, y, d;
};
int n, m;

// 判断当前点是否合法
bool check(int x, int y, int d) {
    if (x < 1 || y < 1 || x > n || y > m)
        return false;
    if (g[x][y] == '#' || st[x][y][d])
        return false;
    return true;
}

void solve() {
    // 读入数据，保存起始点
    cin >> n >> m;
    int x, y;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'S')
                x = i, y = j;
        }

    // 队列初始化
    queue<Node> q;
    q.push({x, y, 0});
    q.push({x, y, 1});
    st[x][y][0] = st[x][y][1] = true;

    // BFS
    while (q.size()) {
        Node now = q.front();
        q.pop();
        int x = now.x, y = now.y, d = now.d;

        // 如果遇到终点，就输出（第一次遇到终点也就是距离最短的时候）
        if (g[x][y] == 'G') {
            cout << dis[x][y][d] << endl;
            return;
        }

        // 遍历下个方向
        for (int i = 2 * d; i < 2 + 2 * d; i++) {
            // d=0时，i=0 1，向左右走 ； d=1时，i= 2 3，向上下走
            int nx = x + dx[i], ny = y + dy[i];
            if (check(nx, ny, !d)) {  // !d 表示翻转方向
                q.push({nx, ny, !d});
                dis[nx][ny][!d] = dis[x][y][d] + 1;
                st[nx][ny][!d] = true;
            }
        }
    }

    cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}