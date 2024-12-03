// Problem: https://www.acwing.com/problem/content/1309/

// 这道题实际上是一道DP
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, MOD = 5e6 + 11;
int f[N], s[N];
int n, k;

void solve() {
    cin >> n >> k;

    f[0] = s[0] = 1;

    for (int i = 1; i <= n; i++) {
        f[i] = s[max(i - k - 1, 0)];
        s[i] = (s[i - 1] + f[i]) % MOD;
    }

    cout << s[n] % MOD << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}