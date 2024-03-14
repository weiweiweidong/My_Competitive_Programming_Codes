// Problem: https://www.acwing.com/problem/content/839/
// 维护size的并查集
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m;
int p[N], cnt[N];

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        p[i] = i;
        cnt[i] = 1;
    }

    while (m--) {
        string op;
        int a, b;
        cin >> op;
        if (op == "C") {
            cin >> a >> b;
            // 如果a和b已经处于一个联通块内，跳过
            if (find(a) == find(b))
                continue;
            // 将b作为ab联通块的祖宗节点，size加到b上面
            cnt[find(b)] += cnt[find(a)];
            // 合并联通块，b作为祖宗节点
            p[find(a)] = find(b);

        } else if (op == "Q1") {
            cin >> a >> b;
            if (find(a) == find(b))
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        } else {
            cin >> a;
            cout << cnt[find(a)] << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}