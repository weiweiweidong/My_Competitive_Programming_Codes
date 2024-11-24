// Problem: https://www.acwing.com/problem/content/1292/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const LL MOD = 100003;
LL m, n;

// 快速幂
LL apow(LL a, LL k, LL mod) {
    LL ans = 1;
    while (k) {
        if (k & 1)
            ans = ans * a % mod;
        k >>= 1;
        a = a * a % mod;
    }
    return ans;
}

void solve() {
    cin >> m >> n;
    /*
    备注：
    在模运算中：
        如果 a ≡ b (mod m)
        那么 a + m ≡ b (mod m)
    当出现负数时，加上一个MOD不会改变最终的同余结果，但可以把负数变成正数，便于计算。
    */
    LL res = (apow(m, n, MOD) - m * apow(m - 1, n - 1, MOD) % MOD + MOD) % MOD;
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}