// Problem: https://atcoder.jp/contests/abc303/tasks/abc303_d
// 状态机DP
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;
LL x, y, z, n;
LL f[N][2];
string s;

void solve() {
    cin >> x >> y >> z;
    cin >> s;
    n = s.size();
    s = " " + s;

    f[0][1] = z;
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') {
            f[i][1] = min(
                {f[i - 1][1] + x, f[i - 1][0] + z + x, f[i - 1][0] + y + z});
            f[i][0] = min({f[i - 1][1] + z + x, f[i - 1][0] + y,
                           f[i - 1][0] + z + x + z});
        } else {
            f[i][1] = min({f[i - 1][0] + x + z, f[i - 1][1] + y,
                           f[i - 1][1] + z + x + z});
            f[i][0] = min(
                {f[i - 1][0] + x, f[i - 1][1] + y + z, f[i - 1][1] + z + x});
        }
    }

    cout << min(f[n][0], f[n][1]) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}