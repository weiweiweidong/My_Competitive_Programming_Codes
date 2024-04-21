// Problem: https://atcoder.jp/contests/abc347/tasks/abc347_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int a, b, c;
LL A, B, C;

// 计算x的二进制表示中有多少个1
int popcount(LL x) {
    int res = 0;
    while (x) {
        res += x & 1;
        x >>= 1;
    }
    return res;
}

int solve() {
    cin >> a >> b >> C;
    int c = popcount(C);

    if (a + b < c || (a + b - c) % 2) {
        cout << -1 << endl;
        return 0;
    }

    int ex = (a + b - c) / 2;

    if (ex + c > 60) {
        cout << -1 << endl;
        return 0;
    }

    a -= ex;
    b -= ex;

    if (a < 0 || b < 0) {
        cout << -1 << endl;
        return 0;
    }

    LL X = 0, Y = 0;
    for (int i = 0; i < 60; i++) {
        if (C >> i & 1) {
            if (a) {
                X |= 1LL << i;
                a--;
            } else {
                Y |= 1LL << i;
                b--;
            }
        } else if (ex) {
            X |= 1LL << i;
            Y |= 1LL << i;
            ex--;
        }
    }

    cout << X << " " << Y << endl;
    return 0;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}