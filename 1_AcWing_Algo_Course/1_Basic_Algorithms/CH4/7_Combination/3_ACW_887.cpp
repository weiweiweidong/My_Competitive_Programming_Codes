// Problem: https://www.acwing.com/problem/content/889/
// 求组合数：使用Lucas定理
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n;

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

int C(int a, int b, int p) {
    if (b > a)
        return 0;

    int res = 1;
    for (int i = 1, j = a; i <= b; i++, j--) {
        res = (LL)res * j % p;
        res = (LL)res * qmi(i, p - 2, p) % p;
    }
    return res;
}

// Lucas 定理
int Lucas(LL a, LL b, int p) {
    if (a < p && b < p)
        return C(a, b, p);
    return (LL)C(a % p, b % p, p) * Lucas(a / p, b / p, p) % p;
}

void solve() {
    cin >> n;
    while (n--) {
        LL a, b;
        int p;
        cin >> a >> b >> p;
        cout << Lucas(a, b, p) << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}