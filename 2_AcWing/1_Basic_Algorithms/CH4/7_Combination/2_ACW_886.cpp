// Problem: https://www.acwing.com/problem/content/888/
// 求组合数：预处理阶乘值
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, MOD = 1e9 + 7;
int fact[N], infact[N];
int n, a, b;

// 快速幂
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

// 预处理阶乘数组
void init() {
    fact[0] = infact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (LL)fact[i - 1] * i % MOD;
        infact[i] = (LL)infact[i - 1] * qmi(i, MOD - 2, MOD) % MOD;
    }
}

void solve() {
    init();

    cin >> n;
    while (n--) {
        cin >> a >> b;
        // 计算组合数
        cout << (LL)fact[a] * infact[b] % MOD * infact[a - b] % MOD << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}