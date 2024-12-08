// Problem: https://www.acwing.com/problem/content/1312/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

// 计算 C(n,3) 的结果
LL C(int n) {
    return (LL)n * (n - 1) * (n - 2) / 6;
}

void solve() {
    int n, m;
    cin >> n >> m;
    n++, m++;  // 格子数量 转化为 格点数量

    // 计算 斜率为0 和 斜率为+∞ 情况
    LL res = C(n * m) - (LL)n * C(m) - (LL)m * C(n);

    // 计算斜边情况
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            res -= 2ll * (gcd(i, j) - 1) * (n - i) * (m - j);

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}