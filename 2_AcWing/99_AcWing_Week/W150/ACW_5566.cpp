// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, m, x, y;

bool check(LL t) {
    // x倍数数量，y倍数数量，xy倍数数量，自由的数量
    LL xy_num = t / (x * y);
    LL x_num = t / x - xy_num;
    LL y_num = t / y - xy_num;
    LL free = t - xy_num - x_num - y_num;

    LL n1 = n, m1 = m;

    n1 = max(0LL, n1 - y_num);
    m1 = max(0LL, m1 - x_num);

    if (n1 + m1 <= free)
        return true;
    else
        return false;
}

void solve() {
    cin >> n >> m >> x >> y;

    LL left = 0, right = 1e18 + 10;
    while (left < right) {
        LL mid = (left + right) / 2;

        if (check(mid))
            right = mid;
        else
            left = mid + 1;
    }

    cout << left << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}