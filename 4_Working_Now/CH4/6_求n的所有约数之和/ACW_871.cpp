#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;
int n, a;

int main() {
    cin >> n;
    unordered_map<int, int> primes;
    while (n--) {
        cin >> a;
        for (int i = 2; i <= a / i; i++) {
            while (a % i == 0) {
                a /= i;
                primes[i]++;
            }
        }
        if (a > 1)
            primes[a]++;
    }

    LL res = 1;
    for (auto [p, v] : primes) {
        LL t = 1;
        // 计算 p^0 + p^1 + p^2 +..... + p^v 的值
        while (v--)
            t = (t * p + 1) % MOD;
        // 把这一项乘进res里
        res = res * t % MOD;
    }

    cout << res << endl;
    return 0;
}