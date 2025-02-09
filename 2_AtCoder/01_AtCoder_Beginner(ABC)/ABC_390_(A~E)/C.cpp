// Problem: https://atcoder.jp/contests/abc390/tasks/abc390_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
char g[N][N];
int h, w;

void solve() {
    cin >> h >> w;
    // 设定初始值
    int left = w, top = h;
    int right = 1, bottom = 1;

    // 读入每一个格子的颜色
    for (int i = 1; i <= h; i++)
        for (int j = 1; j <= w; j++) {
            cin >> g[i][j];
            // 如果遇到黑色格子，就更新一下四个边界参数
            if (g[i][j] == '#') {
                left = min(left, j);
                right = max(right, j);
                top = min(top, i);
                bottom = max(bottom, i);
            }
        }

    // 开始看边界范围内，是否存在白格子
    bool flag = true;
    for (int i = top; i <= bottom; i++)
        for (int j = left; j <= right; j++)
            if (g[i][j] == '.')
                // 只要存在一个白格子，就不能实现要求
                flag = false;

    // 输出结果
    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}