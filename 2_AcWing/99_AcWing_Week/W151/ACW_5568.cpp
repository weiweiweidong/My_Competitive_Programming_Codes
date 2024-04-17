// Problem: https://www.acwing.com/problem/content/5571/
// 组合计数题：隔板法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1E6 + 3;

// 快速幂函数
int qmi(int a, int b, int p) {
    int res = 1 % p;
    while (b) {
        if (b & 1)
            res = (LL)res * a % p;
        a = (LL)a * a % p;
        b >>= 1;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;
    LL res = 1;
    for (int i = n + m, j = 1; j <= m; i--, j++) {
        res = res * i % MOD;
        res = res * qmi(j, MOD - 2, MOD) % MOD;
    }

    // 因为 res-1 后有可能是负数，所以+MOD
    // 本题目虽然res-1不会为负数，但是 (x+MOD)%MOD
    // 的写法是一个模版写法，不容易出错
    cout << (res - 1 + MOD) % MOD << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}