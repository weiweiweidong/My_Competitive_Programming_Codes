// Problem: https://www.acwing.com/problem/content/244/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m;
int a[N];
LL tr1[N];  // 维护 b[i] 的前缀和
LL tr2[N];  // 维护 i*b[i] 的前缀和

int lowbit(int x) {
    return x & -x;
}

void add(LL tr[], int x, LL k) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += k;
}

LL sum(LL tr[], int x) {
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

// 计算 a[] 的前 x 项和
LL prefix_sum(int x) {
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

void solve() {
    cin >> n >> m;
    // 读入原数组
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 初始化树状数组 tr1 和 tr2
    for (int i = 1; i <= n; i++) {
        int b = a[i] - a[i - 1];
        add(tr1, i, b);
        add(tr2, i, (LL)b * i);
    }

    while (m--) {
        char op[2];
        cin >> op;
        int l, r;
        cin >> l >> r;
        // 查询操作：计算出整理后的前缀和
        if (op[0] == 'Q')
            cout << prefix_sum(r) - prefix_sum(l - 1) << endl;
        // 区间维护
        else {
            int d;
            cin >> d;
            add(tr1, l, d), add(tr2, l, l * d);
            add(tr1, r + 1, -d), add(tr2, r + 1, (r + 1) * -d);
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}