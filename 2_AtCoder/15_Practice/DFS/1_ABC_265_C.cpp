// Problem: https://atcoder.jp/contests/abc265/tasks/abc265_c

/*
思路：
    模拟题：从(1,1)点开始按照规则往后走。路上有两种情况：
    1. 可能会进入循环：输出-1
    2. 可能会越界：输出最后一个点坐标即可
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;
char g[N][N];
int H, W;
bool st[N][N];

void solve() {
    cin >> H >> W;
    for (int i = 1; i <= H; i++)
        for (int j = 1; j <= W; j++)
            cin >> g[i][j];

    int x = 1, y = 1;
    bool flag = true;
    while (flag) {
        st[x][y] = true;
        // 计算下一个点的坐标
        int a, b;
        if (g[x][y] == 'U')
            a = x - 1, b = y;
        else if (g[x][y] == 'D')
            a = x + 1, b = y;
        else if (g[x][y] == 'L')
            a = x, b = y - 1;
        else
            a = x, b = y + 1;

        // 如果下一个点进入轮回
        if (st[a][b])
            flag = false;

        // 如果下一个点出界
        if (a < 1 || a > H || b < 1 || b > W)
            break;

        // 更新下一个点坐标
        x = a, y = b;
    }
    if (!flag)
        cout << -1 << endl;
    else
        cout << x << " " << y << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}