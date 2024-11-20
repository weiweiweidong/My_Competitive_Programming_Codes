// Problem: https://www.acwing.com/problem/content/877/
// 快速幂
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a, k, p;

int apow(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1)
            res = res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

void solve() {
    cin >> n;
    while (n--) {
        cin >> a >> k >> p;
        cout << apow(a, k, p) << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}