// Problem: https://atcoder.jp/contests/abc382/tasks/abc382_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
string s;

void solve() {
    cin >> n >> k;
    cin >> s;
    int res = 0;
    for (auto x : s)
        if (x == '.')
            res++;
    cout << res + k << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}