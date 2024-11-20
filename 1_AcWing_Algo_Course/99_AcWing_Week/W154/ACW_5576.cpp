// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    int l, r, x;
    cin >> l >> r >> x;
    if (x >= l && x <= r)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}