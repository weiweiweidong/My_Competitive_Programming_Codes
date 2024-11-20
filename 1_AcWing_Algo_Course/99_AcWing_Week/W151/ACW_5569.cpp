// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const double eps = 1e-8;

// 判断浮点数大小关系，模版
int dcmp(double a, double b) {
    // 相等情况特判
    if (abs(a - b) < eps)
        return 0;
    // a小于b
    if (a < b)
        return -1;
    // a大于b
    return 1;
}

void solve() {
    int n, w, v, u;
    cin >> n >> w >> v >> u;
    double k = (double)u / v, b = 0;
    bool all_right = true, all_left = true;
    while (n--) {
        int x, y;
        cin >> x >> y;
        if (dcmp(y, k * x) > 0)
            all_right = false;
        if (dcmp(y, k * x) < 0)
            all_left = false;
        b = min(b, y - k * x);
    }

    if (all_right || all_left)
        cout << fixed << setprecision(10) << (double)w / u << endl;
    else
        cout << fixed << setprecision(10) << ((double)w - b) / u << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}