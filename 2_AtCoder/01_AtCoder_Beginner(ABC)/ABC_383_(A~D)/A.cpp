// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int n;
    cin >> n;

    int res = 0, last_t = 0;
    for (int i = 1; i <= n; i++) {
        int t, v;
        cin >> t >> v;

        if (res)
            res = max(res - (t - last_t), 0);
        res += v;
        last_t = t;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}