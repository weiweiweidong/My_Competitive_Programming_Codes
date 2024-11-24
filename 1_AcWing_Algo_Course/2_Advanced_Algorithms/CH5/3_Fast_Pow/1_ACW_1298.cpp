// Problem: https://www.acwing.com/problem/content/1291/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const LL MOD = 200907;

LL T, a, b, c, k;
LL res;

// 快速幂
LL apow(LL a, LL k, LL mod) {
    LL ans = 1;
    while (k) {
        if (k & 1)
            ans = (LL)ans * a % mod;
        k >>= 1;
        a = (LL)a * a % mod;
    }
    return ans;
}

void solve() {
    cin >> T;
    while (T--) {
        cin >> a >> b >> c >> k;
        // 等差数列：a+c==2b
        if (a + c == 2 * b) {
            res = a + (k - 1) * (b - a);
            res %= MOD;
        }
        // 等比数列：ac==bb
        else {
            LL q = b / a;
            res = a * apow(q, k - 1, MOD) % MOD;
        }
        // 输出结果
        cout << res << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}