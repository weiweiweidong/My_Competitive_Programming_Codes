// Problem: https://www.acwing.com/problem/content/872/
// 求约数的个数
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

        // 质因数分解：
        for (int i = 2; i <= x / i; i++) {
            while (x % i == 0) {
                x /= i;
                primes[i]++;
            }
        }
        if (x > 1)
            primes[x]++;
    }

    // 求约数的个数
    LL res = 1;
    for (auto [p, v] : primes)
        res = res * (v + 1) % MOD;

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}