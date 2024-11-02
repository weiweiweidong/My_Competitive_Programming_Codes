// Problem:

/*
问题设定：
    n*n 的棋盘，有 m 个已放置的棋子。
    棋子会消除掉同一行，同一列，主对角线，副对角线的空格。求剩余的空格数量。

思路：
1. 正难则反：能放棋子的位置数量=总位置数量 N*N- 不能放棋子的位置数量
2. 每多一个棋子，就有一行，一列，主对角线（x-y 是定值），副对角线（x+y是定值）
不能放棋子
3. 如何统计？
    如果只考虑行和列的限制：能放棋子的数量 = (n-行数)*(n-列数)
    加入主对角线限制：主对角线长度-其和行列的交点的数量（交点可能还要去重）
    加入副对角线限制：副对角线长度-其和行列、主对角线的交点的数量（交点需要去重）

技巧：
    可以使用 x-y 来定义主对角线，用 x+y 定义副对角线
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;  // n是棋盘大小，m是已放棋子数

// hori: 存放已有棋子的行号
// vert: 存放已有棋子的列号
// diag: 存放已有棋子的主对角线(左上到右下)
// anti_diag: 存放已有棋子的副对角线(右上到左下)
set<int> hori, vert, diag, anti_diag;  // 用集合存储已占用的行、列和对角线位置

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        int x, y;
        cin >> x >> y;
        hori.insert(x);
        vert.insert(y);
        diag.insert(x - y);       // 主对角线特征：x-y相同
        anti_diag.insert(x + y);  // 副对角线特征：x+y相同
    }

    // 初步计算答案（去除掉同行同列的格子）
    LL ans = (LL)(n - hori.size()) * (n - vert.size());

    // 处理主对角线
    for (int d : diag) {   // 遍历每条已占用的主对角线
        set<int> cross_x;  // 记录交点的x坐标

        // 计算与水平线的交点
        for (int x : hori) {
            int y = x - d;          // 根据 d = x-y 算出y
            if (1 <= y && y <= n)   // 如果y在棋盘范围内
                cross_x.insert(x);  // 记录交点
        }

        // 计算与垂直线的交点
        for (int y : vert) {
            int x = d + y;          // 根据 d = x-y 算出x
            if (1 <= x && x <= n)   // 如果x在棋盘范围内
                cross_x.insert(x);  // 记录交点，同时去重
        }

        int cross_num = cross_x.size();  // 交点数
        int d_len = n - abs(d);          // 这条对角线在棋盘上的长度
        ans -= d_len - cross_num;        // 减去新增的限制点数
    }

    // 处理副对角线
    for (int e : anti_diag) {  // 遍历每条已占用的副对角线
        set<int> cross_x;

        // 计算与水平线的交点
        for (int x : hori) {
            int y = e - x;  // 根据 e = x+y 算出y
            if (1 <= y && y <= n)
                cross_x.insert(x);
        }

        // 计算与垂直线的交点
        for (int y : vert) {
            int x = e - y;  // 根据 e = x+y 算出x发动机上课垃圾费今飞凯加分
            if (1 <= x && x <= n)
                cross_x.insert(x);
        }

        // 计算与主对角线的交点
        for (int d : diag) {
            int x = (d + e) / 2;  // 解方程组 x-y=d, x+y=e
            int y = (e - d) / 2;  // 得到交点坐标
            if ((d + e) % 2 == 0 && 1 <= x && x <= n && 1 <= y && y <= n) {
                cross_x.insert(x);
            }
        }

        int cross_num = cross_x.size();
        int e_len = n - abs(e - (n + 1));  // 这条副对角线在棋盘上的长度
        ans -= e_len - cross_num;          // 减去新增的限制点数
    }

    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}