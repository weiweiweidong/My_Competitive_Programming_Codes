// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5;
int a[N], b[N], c[N];
int n, q;
string s;
int v[N];  // 存储每个/的位置

void solve() {
    cin >> n >> q >> s;
    s = " " + s;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1], b[i] = b[i - 1], c[i] = c[i - 1];
        if (s[i] == '1')
            a[i]++;
        if (s[i] == '/') {
            b[i]++;
            v[cnt++] = i;
        }
        if (s[i] == '2')
            c[i]++;
    }
    int n;

    vector<PII> k;  // 存储每个查询
    for (int i = 0; i < q; i++) {
        int L, R;
        cin >> L >> R;
        k.push_back({L, R});
    }

    for (auto t : k) {
        int res = 0;
        int L = t.first, R = t.second;

        int l = lower_bound(v, v + cnt, L) - v;
        int r = upper_bound(v, v + cnt, R) - v - 1;

        for (int i = l; i <= r; i++) {
            int pos = v[i];
            int temp = min(a[pos] - a[L - 1], c[R] - c[pos]);
            res = max(res, temp * 2 + 1);
        }

        cout << res << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}