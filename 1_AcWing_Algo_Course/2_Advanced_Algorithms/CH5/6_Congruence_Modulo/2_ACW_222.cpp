// Problem: https://www.acwing.com/problem/content/224/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL exgcd(LL a, LL b, LL& x, LL& y) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

void solve() {
    LL a, b, m, n, L;
    LL x, y;
    cin >> a >> b >> m >> n >> L;

    LL d = exgcd(m - n, L, x, y);
    // 如果 d 不能整除 b-a，说明无解
    if ((b - a) % d)
        cout << "Impossible" << endl;
    // 计算解
    else {
        x *= (b - a) / d;  // 扩大
        LL t = abs(L / d);
        cout << (x % t + t) % t << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}