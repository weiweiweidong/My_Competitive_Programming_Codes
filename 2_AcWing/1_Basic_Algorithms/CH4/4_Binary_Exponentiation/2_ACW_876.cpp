// Problem: https://www.acwing.com/problem/content/878/
// 快速幂求逆元
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a, p;

int qmi(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1)
            res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

void solve() {
    cin >> n;
    while (n--) {
        cin >> a >> p;
        int res = qmi(a, p - 2, p);

        if (a % p)
            cout << res << endl;
        else
            cout << "impossible" << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}