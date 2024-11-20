// Problem: https://www.acwing.com/problem/content/99/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int mod = 9901;

int qmi(int a, int k) {
    int res = 1;
    a %= mod;
    while (k) {
        if (k & 1)
            res = res * a % mod;
        a = a * a % mod;
        k >>= 1;
    }
    return res;
}

int sum(int p, int k) {
    if (k == 1)
        return 1;
    if (k % 2 == 0)
        return (1 + qmi(p, k / 2)) * sum(p, k / 2) % mod;
    else
        return (sum(p, k - 1) + qmi(p, k - 1)) % mod;
}

void solve() {
    int a, b;
    scanf("%d%d", &a, &b);

    int res = 1;
    // 对a分解质因数
    for (int i = 2; i * i <= a; i++) {
        if (a % i == 0) {
            int s = 0;
            while (a % i == 0) {
                a /= i, s++;
            }
            res = res * sum(i, b * s + 1) % mod;
        }
    }

    if (a > 1)
        res = res * sum(a, b + 1) % mod;
    if (a == 0)
        res = 0;

    printf("%d\n", res);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}