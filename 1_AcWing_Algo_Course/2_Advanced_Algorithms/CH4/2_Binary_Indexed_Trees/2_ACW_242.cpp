// Problem: https://www.acwing.com/problem/content/248/

// “区间修改，单点查询” 类型题目
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m;
int a[N];  // 储存原数组
LL tr[N];  // 树状数组（用来储存差分数组）

int lowbit(int x) {
    return x & -x;
}

// 在 x 位置加上值 c
void add(int x, LL c) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

// 求前 x 项的和
LL sum(int x) {
    LL res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

void solve() {
    cin >> n >> m;
    // 读入原数组
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 用树状数组储存差分数组
    for (int i = 1; i <= n; i++)
        add(i, a[i] - a[i - 1]);

    while (m--) {
        char op[2];
        cin >> op;
        // 如果操作为 C：
        if (op[0] == 'C') {
            int l, r, d;
            cin >> l >> r >> d;
            add(l, d), add(r + 1, -d);
        }
        // 如果操作为 Q
        else {
            int x;
            cin >> x;
            cout << sum(x) << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}