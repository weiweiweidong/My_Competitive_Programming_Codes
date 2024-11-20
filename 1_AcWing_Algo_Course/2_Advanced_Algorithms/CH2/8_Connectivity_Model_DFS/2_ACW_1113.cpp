// Problem: https://www.acwing.com/problem/content/1115/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 25;
char g[N][N];
bool st[N][N];
int H, W;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int dfs(int x, int y) {
    int cnt = 1;  // 包含当前点
    st[x][y] = true;

    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= H || b < 0 || b >= W)
            continue;
        if (g[a][b] != '.')
            continue;
        if (st[a][b])
            continue;
        cnt += dfs(a, b);  // 继续向下走
    }
    return cnt;  // 返回结果
}

void solve() {
    while (true) {
        cin >> W >> H;
        if (!W && !H)
            break;
        // 读入网络
        for (int i = 0; i < H; i++)
            cin >> g[i];
        // 找到起点
        int x, y;
        for (int i = 0; i < H; i++)
            for (int j = 0; j < W; j++)
                if (g[i][j] == '@')
                    x = i, y = j;
        // st 初始化
        memset(st, 0, sizeof st);
        // 输出结果
        cout << dfs(x, y) << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}