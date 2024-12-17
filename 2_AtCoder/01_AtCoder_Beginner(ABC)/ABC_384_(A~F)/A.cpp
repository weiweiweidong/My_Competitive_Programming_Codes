// Problem: https://atcoder.jp/contests/abc384/tasks/abc384_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n;
char a, b;
string s;

void solve() {
    cin >> n >> a >> b >> s;
    for (auto& x : s)
        if (x != a)
            x = b;

    cout << s << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}