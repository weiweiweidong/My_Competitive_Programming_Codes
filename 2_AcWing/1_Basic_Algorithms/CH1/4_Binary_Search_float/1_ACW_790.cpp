// Problem: https://www.acwing.com/problem/content/792/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

double n;

void solve() {
    cin >> n;
    double l = -100, r = 100;
    while (r - l > 1e-8) {
        double mid = (l + r) / 2;
        if (mid * mid * mid >= n)
            r = mid;
        else
            l = mid;
    }
    // 保留6位小数输出
    printf("%.6lf\n", l);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
}