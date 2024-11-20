// Problem: https://www.acwing.com/problem/content/899/
// 最长公共子序列
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
    cin >> n >> m;
    cin >> A >> B;
    A = " " + A, B = " " + B;

    // 状态转移
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            if (A[i] == B[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    cout << f[n][m] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}