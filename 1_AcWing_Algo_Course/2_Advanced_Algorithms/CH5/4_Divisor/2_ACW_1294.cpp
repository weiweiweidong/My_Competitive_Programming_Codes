// Problem: https://www.acwing.com/problem/content/1296/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10, MOD = 1e9 + 7;

int primes[N], cnt;
bool st[N];
int n;

// 预处理出n 以内的所有的质数
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve() {
    cin >> n;

    get_primes(n);

    int res = 1;
    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        int s = 0;
        // n! 的分解
        for (int j = n; j; j /= p)
            s += j / p;
        res = (LL)res * (2 * s + 1) % MOD;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}