// Problem: https://www.acwing.com/problem/content/843/
// 字符串哈希
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// unsigned long long 处理后，溢出的值相当于是 模2^64
typedef unsigned long long ULL;
// P为经验值，取131或13331，基本不可能有冲突
const int N = 1e5 + 10, P = 131;
int n, m;
char str[N];
ULL h[N], p[N];

// 获取 l～r 之间字符串的哈希值
ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

void solve() {
    cin >> n >> m >> (str + 1);
    // p的0次方，值为1
    p[0] = 1;
    // 预处理p的幂次 和 字符串哈希值
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }

    while (m--) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        if (get(l1, r1) == get(l2, r2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}