// Problem: https://www.acwing.com/problem/content/1114/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 120;
char g[N][N];
int k, n;
int xa, ya, xb, yb;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
bool st[N][N];

// 判断当前点(x,y)能否走到目标点(xb,yb)
bool dfs(int x, int y) {
    if (g[x][y] == '#')
        return false;
    if (x == xb && y == yb)
        return true;

    st[x][y] = true;

    // 遍历四个方向
    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        // 判断是否出界
        if (a < 0 || a >= n || b < 0 || b >= n)
            continue;
        // 判断是否被遍历过了
        if (st[a][b])
            continue;
        // 判断是否为障碍物
        if (g[a][b] == '#')
            continue;
        // 向下走
        if (dfs(a, b))
            return true;
    }
    // 注意：此处不需要恢复现场
    // 如果是棋盘这种整体作为状态时，需要恢复现场；如果每个格子作为状态，不需要恢复现场（每个点只会被遍历一次）
    return false;
}

void solve() {
    cin >> k;
    while (k--) {
        cin >> n;
        for (int i = 0; i < n; i++)
            cin >> g[i];
        cin >> xa >> ya >> xb >> yb;

        memset(st, 0, sizeof st);  // st 被多次使用，这里必须要重置 st
        if (dfs(xa, ya))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}