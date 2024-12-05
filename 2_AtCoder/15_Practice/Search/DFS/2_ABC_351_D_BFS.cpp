// Problem: https://atcoder.jp/contests/abc351/tasks/abc351_d
// 2024-12-04
// BFS 最大连通区域问题

/*
    本解法的关键是：将网格中'#'周围的点标记为'?'
    那么网格中就有三种符号：
        . 表示可以往周围的四方向走
        # 无法走到这个位置
        ? 走到这里就停止
    Reference：https://atcoder.jp/contests/abc351/submissions/52864035
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
char g[N][N];   // 存储网格
int vis[N][N];  // 记录各个点遍历的轮数
struct node {
    int x, y;
};
int h, w;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

// 检查 (x,y) 合规性
bool check(int x, int y, int turn) {
    if (x < 1 || x > h || y < 1 || y > w)
        return false;
    if (g[x][y] == '#')
        return false;
    if (vis[x][y] == turn)
        return false;
    return true;
}

void solve() {
    cin >> h >> w;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            cin >> g[i][j];

    // 把'#'周围的'.'改成'?'
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            if (g[i][j] == '#')
                for (int k = 0; k < 4; k++)
                    if (g[i + dx[k]][j + dy[k]] == '.')
                        g[i + dx[k]][j + dy[k]] = '?';

    int res = 1;
    int turn = 0;
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++)
            if (g[i][j] == '.') {
                turn++;
                queue<node> q;
                q.push({i, j});
                vis[i][j] = turn;
                int cnt = 1;

                while (q.size()) {
                    int now_x = q.front().x, now_y = q.front().y;
                    q.pop();
                    if (g[now_x][now_y] == '?')
                        continue;
                    g[now_x][now_y] = '?';
                    for (int k = 0; k < 4; k++) {
                        int next_x = now_x + dx[k], next_y = now_y + dy[k];

                        if (check(next_x, next_y, turn)) {
                            q.push({next_x, next_y});
                            vis[next_x][next_y] = turn;
                            cnt++;
                        }
                    }
                }
                res = max(res, cnt);
            }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}