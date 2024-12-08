// Problem: https://www.acwing.com/problem/content/1314/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e6 + 3;

// 快速幂模板
int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1)
            res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}

// 计算组合数 C(a,b) mod p
int C(int a, int b, int p) {
    if (a < b)
        return 0;
    int down = 1, up = 1;
    for (int i = a, j = 1; j <= b; i--, j++) {
        up = (LL)up * i % p;
        down = (LL)down * j % p;
    }
    return (LL)up * qmi(down, p - 2, p) % p;
}

// Lucas 定理：大组合数取模
int Lucas(int a, int b, int p) {
    if (a < p && b < p)
        return C(a, b, p);
    return (LL)Lucas(a / p, b / p, p) * C(a % p, b % p, p) % p;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        int n, l, r;
        cin >> n >> l >> r;
        cout << (Lucas(r - l + n + 1, r - l + 1, MOD) + MOD - 1) % MOD << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}