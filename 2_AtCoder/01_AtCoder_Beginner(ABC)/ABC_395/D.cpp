// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int p[N], q[N], r[N];
int n, m;

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        p[i] = q[i] = r[i] = i;

    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            p[a] = r[b];
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            q[r[a]] = b;
            q[r[b]] = a;
            swap(r[a], r[b]);
        } else {
            int a;
            cin >> a;
            cout << q[p[a]] << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}