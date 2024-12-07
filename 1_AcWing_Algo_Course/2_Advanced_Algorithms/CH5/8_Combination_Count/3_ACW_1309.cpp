// Problem: https://www.acwing.com/problem/content/1311/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010, MOD = 100003;
int fact[N];    // 计算阶乘数组，存储 0~N-1 的阶乘
int infact[N];  // 计算逆元。取模情况下，除法转变为乘以逆元

// 快速幂
int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = (LL)res * a % p;  // 这里非常容易溢出
        a = (LL)a * a % p;          // 这里非常容易溢出
        b >>= 1;
    }
    return res;
}

// 计算组合数
int C(int a, int b) {
    if (a < b)
        return 0;
    return (LL)fact[a] * infact[a - b] % MOD * infact[b] % MOD;
}

// 计算排列数
int P(int a, int b) {
    if (a < b)
        return 0;
    return (LL)fact[a] * infact[a - b] % MOD;
}

void solve() {
    // 预处理 阶乘 和 阶乘逆元
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (LL)fact[i - 1] * i % MOD;
        infact[i] = (LL)infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
    }

    // 读入数据
    int a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;

    // 代入公式，迭代计算结果
    int res = 0;
    for (int i = 0; i <= k; i++) {
        res = (res + (LL)C(b, i) * P(a, i) % MOD * C(d, k - i) % MOD *
                         P(a + c - i, k - i) % MOD) %
              MOD;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}