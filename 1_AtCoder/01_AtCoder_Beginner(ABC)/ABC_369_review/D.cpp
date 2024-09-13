// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
LL f[N][2][2];

void solve() {
    int n;
    cin >> n;
    LL val;
    for (int i = 1; i <= n; i++) {
        cin >> val;
        if (i != 1)
            f[i][0][0] = max(f[i - 1][0][0], f[i - 1][0][1]);
        if (i != 1)
            f[i][0][1] = max(f[i - 1][1][0], f[i - 1][1][1]) + val + val;
        f[i][1][0] = max(f[i - 1][1][0], f[i - 1][1][1]);
        f[i][1][1] = max(f[i - 1][0][0], f[i - 1][0][1]) + val;
    }

    LL max_val = -1;
    max_val = max(max_val, f[n][0][0]);
    max_val = max(max_val, f[n][0][1]);
    max_val = max(max_val, f[n][1][0]);
    max_val = max(max_val, f[n][1][1]);

    cout << max_val << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}