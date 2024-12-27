// Problem: https://atcoder.jp/contests/abc378/tasks/abc378_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a;
unordered_map<int, int> q;
void solve() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a;
        if (!q.count(a))
            cout << -1 << " ";
        else
            cout << q[a] << " ";

        q[a] = i;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}