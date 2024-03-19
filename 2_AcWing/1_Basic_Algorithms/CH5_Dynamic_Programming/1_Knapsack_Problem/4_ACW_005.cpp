// Problem: https://www.acwing.com/problem/content/5/
// 多重背包问题的二进制优化写法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 25000, M = 2010;
int n, m;
int f[N];
int v[N], w[N];

void solve() {
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a, b, s;
        cin >> a >> b >> s;
        // 将s个物品拆分成包
        int k = 1;
        while (k <= s) {
            cnt++;
            v[cnt] = k * a;
            w[cnt] = k * b;
            s -= k;
            k *= 2;
        }
        // 如果最后还剩下一些，就单独打包
        if (s > 0) {
            cnt++;
            v[cnt] = s * a;
            w[cnt] = s * b;
        }
    }
    // 更新物品数量
    n = cnt;
    // 写一遍01背包问题的代码
    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[m] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
