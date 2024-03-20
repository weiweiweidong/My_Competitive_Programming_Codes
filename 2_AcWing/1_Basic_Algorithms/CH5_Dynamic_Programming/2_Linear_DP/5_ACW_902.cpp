// Problem: https://www.acwing.com/problem/content/904/
// 最短编辑距离
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
int n, m;
string A, B;
int f[N][N];

void solve() {
    // 读入数据
    cin >> n >> A >> m >> B;
    A = " " + A, B = " " + B;

    // 初始化
    for (int i = 0; i <= m; i++)
        f[0][i] = i;  // 表示A的0个字符变为B的i个字符，需要i次操作
    for (int i = 0; i <= n; i++)
        f[i][0] = i;  // 表示A的i个字符变为B的0个字符，需要i次操作

    // 状态转移
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
            if (A[i] == B[j])
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            else
                f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1);
        }
    }

    // 输出结果
    cout << f[n][m] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}