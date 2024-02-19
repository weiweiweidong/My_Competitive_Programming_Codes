#include <bits/stdc++.h>
#define int long long
using namespace std;

const int M = 998244353, mx = 6e5;
int q, s[mx], ans = 1, be = 1, en = 1, a[mx];

signed main() {
    s[1] = a[1] = 1;
    // 预处理10的幂次
    for (int i = 2; i <= mx; ++i) {
        s[i] = (s[i - 1] * 10) % M;
    }
    cin >> q;
    while (q--) {
        int op, x;
        cin >> op;
        // 末尾加一位
        if (op == 1) {
            cin >> x;
            a[++en] = x, ans = (ans * 10 + x) % M;
        }
        // 头部删一位
        else if (op == 2) {
            // 这里加上 10倍MOD 是为了避免相减后变为负数
            ans = (ans - a[be] * s[en - be + 1] + M * 10) % M, be++;
        }
        // 输出结果
        else {
            cout << ans << '\n';
        }
    }
    return 0;
}