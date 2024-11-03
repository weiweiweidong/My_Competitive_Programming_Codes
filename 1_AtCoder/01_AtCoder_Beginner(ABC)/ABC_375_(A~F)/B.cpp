// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    double res = 0;
    LL lx = 0, ly = 0;
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        LL x, y;
        cin >> x >> y;
        res += sqrt((x - lx) * (x - lx) + (y - ly) * (y - ly));
        lx = x, ly = y;
    }
    res += sqrt((lx) * (lx) + (ly) * (ly));

    // 设定 6 位小数
    cout << setiosflags(ios::fixed) << setprecision(6) << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}