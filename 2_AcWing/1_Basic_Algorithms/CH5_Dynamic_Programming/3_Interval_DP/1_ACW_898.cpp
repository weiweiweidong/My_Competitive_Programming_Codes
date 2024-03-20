// Problem: https://www.acwing.com/problem/content/284/
// 区间DP：合并石子
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 310;
int n;
int s[N];
int f[N][N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> s[i];
    for (int i = 1; i <= n; i++)
        s[i] += s[i - 1];

    // 第一层循环：遍历区间长度
    for (int len = 2; len <= n; len++) {
        // 第二层循环：遍历起始点
        for (int i = 1; i + len - 1 <= n; i++) {
            int l = i, r = i + len - 1;
            f[l][r] = 1e9;
            // 第三层循环：遍历区间断点
            for (int k = l; k < r; k++)
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
        }
    }
    // 输出结果
    cout << f[1][n] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}