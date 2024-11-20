// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

unordered_map<LL, double> dp;
LL N, A, X, Y;

double f(LL x) {
    if (!x)
        return 0;
    auto it = dp.find(x);

    if (it != dp.end())
        return it->second;

    double ret1 = f(x / A) + X;

    double v = 0;
    for (int i = 2; i <= 6; i++)
        v += f(x / i);
    double ret2 = (v + 6 * Y) / 5;

    dp[x] = min(ret1, ret2);
    return dp[x];
}

void solve() {
    cin >> N >> A >> X >> Y;
    cout << fixed << setprecision(12) << f(N) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}