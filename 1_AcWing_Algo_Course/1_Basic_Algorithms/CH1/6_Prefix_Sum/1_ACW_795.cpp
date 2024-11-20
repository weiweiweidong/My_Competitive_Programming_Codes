// Problem: https://www.acwing.com/problem/content/797/
// 一维前缀和
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int q[N], s[N];
int n, m;

// 注意：为了方便，原数组q 和 前缀和数组s 的下标都从1开始
void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> q[i];
        s[i] = s[i - 1] + q[i];
    }

    while (m--) {
        int l, r;
        cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}