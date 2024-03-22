// Problem: https://www.acwing.com/problem/content/873/
// 约数之和
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;
int n, x;
unordered_map<int, int> primes;

void solve() {
    cin >> n;
    while (n--) {
        cin >> x;

        // 分解质因数
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1)
            primes[x]++;
    }

    LL res = 1;
    // 求约数之和
    for (auto [p, v] : primes) {
        LL t = 1;
        while (v--)
            t = (t * p + 1) % MOD;
        res = res * t % MOD;
    }
    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}