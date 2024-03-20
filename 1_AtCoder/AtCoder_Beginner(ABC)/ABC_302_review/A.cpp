// Problem: https://atcoder.jp/contests/abc302/tasks/abc302_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

void solve() {
    LL A, B;
    cin >> A >> B;
    cout << ((A % B) ? A / B + 1 : A / B) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}