// Problem: https://www.acwing.com/problem/content/220/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 14;
const double INF = 1e20;
int A, B, C, D;
/*
6维度的记忆化数组，各个维度表示：
    f[a][b][c][d][x][y]表示当前状态下的期望值
    前四个维度，abcd 分别表示已经拥有的 ABCD 四种牌的数量
    xy 表示两张王的状态：
        0 表示替换成 A 牌
        1 表示替换成 B 牌
        2 表示替换成 C 牌
        3 表示替换成 D 牌
        4 表示未确定或者空
*/
double f[N][N][N][N][5][5];

double dp(int a, int b, int c, int d, int x, int y) {
    double& v = f[a][b][c][d][x][y];
    if (v >= 0)
        return v;

    // 算一下真实的分配量
    int as = a + (x == 0) + (y == 0);
    int bs = b + (x == 1) + (y == 1);
    int cs = c + (x == 2) + (y == 2);
    int ds = d + (x == 3) + (y == 3);
    // 如果已经超过目标了，就不用再分了
    if (as >= A && bs >= B && cs >= C && ds >= D)
        return v = 0;

    // 算一下已经被分掉的牌
    int sum = a + b + c + d + (x != 4) + (y != 4);
    // 算一下剩下的牌
    sum = 54 - sum;
    if (sum <= 0)
        return v = INF;

    v = 1;

    /* 开始分配牌 */
    // 分给红桃（即a）
    if (a < 13)
        v += (13.0 - a) / sum * dp(a + 1, b, c, d, x, y);
    // 分给黑桃（即b）
    if (b < 13)
        v += (13.0 - b) / sum * dp(a, b + 1, c, d, x, y);
    // 分给梅花（即c）
    if (c < 13)
        v += (13.0 - c) / sum * dp(a, b, c + 1, d, x, y);
    // 分给方片（即d）
    if (d < 13)
        v += (13.0 - d) / sum * dp(a, b, c, d + 1, x, y);
    // 如果小王还没使用，就依次分给四种花色，取最小值
    if (x == 4) {
        double t = INF;
        for (int i = 0; i < 4; i++)
            t = min(t, 1.0 / sum * dp(a, b, c, d, i, y));
        v += t;
    }
    // 如果大王还没使用，就依次分给四种花色，取最小值
    if (y == 4) {
        double t = INF;
        for (int i = 0; i < 4; i++)
            t = min(t, 1.0 / sum * dp(a, b, c, d, x, i));
        v += t;
    }

    // 返回北仑分配的结果
    return v;
}

void solve() {
    // 读入数据
    cin >> A >> B >> C >> D;
    // f 初始化
    memset(f, -1, sizeof f);

    // 开始分配牌
    double t = dp(0, 0, 0, 0, 4, 4);

    // 如果结果 t 还是非常大，说明无解
    if (t > INF / 2)
        t = -1;

    // 输出最终结果
    cout << fixed << setprecision(3) << t << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}