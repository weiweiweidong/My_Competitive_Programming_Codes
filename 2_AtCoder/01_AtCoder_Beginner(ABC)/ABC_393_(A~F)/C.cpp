// Problem: https://atcoder.jp/contests/abc393/tasks/abc393_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int a, b;
set<PII> s;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        if (a == b)
            continue;
        if (a < b)
            swap(a, b);
        s.insert({a, b});
    }

    cout << m - s.size() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}