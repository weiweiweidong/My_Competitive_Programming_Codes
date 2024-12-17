// Problem: https://atcoder.jp/contests/abc384/tasks/abc384_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, r;
int d, a;

void solve() {
    cin >> n >> r;
    for (int i = 1; i <= n; i++) {
        cin >> d >> a;
        // 参加 div1，并且 rating 在 [1600,2799] 之间
        if (d == 1 && r >= 1600 && r <= 2799)
            r += a;
        // 参加 div2，并且 rating 在 [1200,2399] 之间
        else if (d == 2 && r >= 1200 && r <= 2399)
            r += a;
        // 否则跳过
        else
            continue;
    }
    cout << r << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}