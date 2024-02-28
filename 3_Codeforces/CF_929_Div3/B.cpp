#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL n;
LL dp[3];
inline void solve() {
    cin >> n;
    LL sum = 0;
    memset(dp, 0, sizeof dp);

    for (LL i = 0; i < n; i++) {
        LL x;
        cin >> x;
        x = x % 3;
        sum += x;
        dp[x]++;
    }

    // sum为3的倍数
    if (sum % 3 == 0)
        cout << "0" << endl;
    // 如果余数为2，选一个元素+1
    else if (sum % 3 == 2)
        cout << "1" << endl;
    // 如果余数为1
    else if (sum % 3 == 1 && dp[1] >= 1)
        cout << "1" << endl;
    else if (sum % 3 == 1 && dp[1] == 0 && dp[2] >= 2)
        cout << 2 << endl;
    else
        cout << 0 << endl;
}
inline void pre_work() {}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    pre_work();

    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}