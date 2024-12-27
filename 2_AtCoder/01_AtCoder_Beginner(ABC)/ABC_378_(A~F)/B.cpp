// Problem: https://atcoder.jp/contests/abc378/tasks/abc378_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int q[N], r[N];
int n, Q;

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> q[i] >> r[i];

    cin >> Q;
    for (int i = 1, t, d; i <= Q; i++) {
        cin >> t >> d;
        int tmp = d % q[t];

        // 如果 tmp 在 r[t] 前面，说明本轮就可以扔
        if (tmp <= r[t])
            cout << d + (r[t] - tmp) << endl;
        // 否则要等到下一轮才能扔
        else
            cout << d + q[t] - tmp + r[t] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}