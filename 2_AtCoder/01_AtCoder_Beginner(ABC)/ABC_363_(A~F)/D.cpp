// Problem: https://atcoder.jp/contests/abc363/tasks/abc363_d

// 找第n大的回文数
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL N;

// 快速幂模板
LL qpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res *= a;
        a *= a;
        b >>= 1;
    }
    return res;
}

void solve() {
    cin >> N;

    // 特判
    if (N == 1) {
        cout << 0 << endl;
        return;
    }

    // 偏移量修正（把0给修正掉）
    N--;

    // 枚举回文串数字的位数
    for (int d = 1;; d++) {
        // 回文串数字对称轴左侧的位数
        int x = (d + 1) / 2;

        if (N <= 9 * qpow(10, x - 1)) {
            string S = to_string(qpow(10, x - 1) + N - 1);
            // 把S长度扩展为d，后面不足的位置用' '补充
            S.resize(d, ' ');

            // 把后面的空位补上
            for (int i = x; i < d; i++)
                S[i] = S[d - 1 - i];
            cout << S << endl;
            return;
        } else {
            N -= 9 * qpow(10, x - 1);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}