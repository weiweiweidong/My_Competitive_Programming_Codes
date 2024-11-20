// Problem:

// 模拟题目
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, Q;
int L, R;
char op[2];
int t;
int res;

// a 起点，b 障碍，c 终点
int move(int a, int b, int c) {
    if (a < b && b < c)
        return a + n - c;
    if (a < c && c < b)
        return c - a;
    if (b < c && c < a)
        return a - c;
    if (b < a && a < c)
        return c - a;
    if (c < a && a < b)
        return a - c;
    if (c < b && b < a)
        return c + n - a;
    return 0;
}

void solve() {
    cin >> n >> Q;
    L = 1, R = 2;
    while (Q--) {
        cin >> op >> t;
        if (*op == 'L')
            res += move(L, R, t), L = t;
        if (*op == 'R')
            res += move(R, L, t), R = t;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}