// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int A[N], n;
LL sum[N], f[N], k, g_all = 0;
LL p = 998244353;
map<LL, LL> g;

// 用不上
LL power(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1)
            ret = ret * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ret;
}

void solve() {
    // 读入数据
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    // 计算前缀和
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + A[i];
    }

    f[0] = 1;   // 空序列的状态数为1
    g[0] = 1;   // 记录前缀和为0的情况
    g_all = 1;  // 总方案数初始化为1

    for (int i = 1; i <= n; i++) {
        f[i] = (g_all - g[sum[i] - k] + p) % p;
        g[sum[i]] = (g[sum[i]] + f[i]) % p;
        g_all = (g_all + f[i]) % p;
    }
    cout << f[n] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}