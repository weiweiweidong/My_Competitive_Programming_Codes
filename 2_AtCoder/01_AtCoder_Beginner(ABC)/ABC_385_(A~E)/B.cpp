// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
char g[N][N];
int h, w, x, y;
string s;
bool st[N][N];
int dx[4] = {-1, 1, 0, 0}, dy[4] = {0, 0, -1, 1};
int res;

// 转换函数：把 UDLR 转换为 idx
int trans(char c) {
    if (c == 'U')
        return 0;
    else if (c == 'D')
        return 1;
    else if (c == 'L')
        return 2;
    else
        return 3;
}

void solve() {
    // 读入数据
    cin >> h >> w >> x >> y;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> g[i][j];
    cin >> s;
    // 1-base 转换为 0-base
    x--, y--;
    // 遍历每个指令
    for (auto c : s) {
        int d = trans(c);
        // 计算下一个点的坐标
        int a = x + dx[d], b = y + dy[d];
        // 越界
        if (a < 0 || a >= h || b < 0 || b >= w)
            continue;
        // 撞墙
        if (g[a][b] == '#')
            continue;
        // 如果是第一次遇见'@'，计数+1
        if (g[a][b] == '@' && !st[a][b]) {
            st[a][b] = true;
            res++;
        }
        // 更新坐标
        x = a, y = b;
    }

    // 输出结果
    cout << x + 1 << " " << y + 1 << " " << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}