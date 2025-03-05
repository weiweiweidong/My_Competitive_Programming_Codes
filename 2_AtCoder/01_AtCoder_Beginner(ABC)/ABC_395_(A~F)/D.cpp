// Problem: https://atcoder.jp/contests/abc395/tasks/abc395_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int p[N], q[N], r[N];
int n, m;
int op, a, b;

void solve() {
    cin >> n >> m;

    // 初始化
    for (int i = 1; i <= n; i++)
        p[i] = q[i] = r[i] = i;

    // 读入所有的操作
    while (m--) {
        cin >> op;

        // 操作 1：将【鸽子编号 a】 放入【门牌编号 b】的鸽子笼中
        if (op == 1) {
            cin >> a >> b;
            p[a] = r[b];
        }
        // 操作 2：将【门牌编号 a】和【门牌编号 b】的鸽子笼相互交换
        else if (op == 2) {
            cin >> a >> b;
            q[r[a]] = b;
            q[r[b]] = a;
            swap(r[a], r[b]);
        }
        // 输出【鸽子编号 a】目前所在鸽子笼的【门牌编号】
        else {
            cin >> a;
            cout << q[p[a]] << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}