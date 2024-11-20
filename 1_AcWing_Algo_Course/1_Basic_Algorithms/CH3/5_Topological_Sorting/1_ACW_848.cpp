// Problem: https://www.acwing.com/problem/content/850/
// 拓扑排序，使用 数组模拟邻接表 和 数组模拟队列
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m;
int h[N], e[N], ne[N], idx;
int q[N], tt, hh;
int d[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool topo_sort() {
    int tt = -1, hh = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q[++tt] = i;
        }
    }

    while (hh <= tt) {
        int now = q[hh++];
        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            d[next]--;
            if (d[next] == 0)
                q[++tt] = next;
        }
    }
    return tt == n - 1;
}

void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
        d[b]++;  // 计算b的入度
    }

    if (!topo_sort())
        cout << "-1" << endl;
    else {
        for (int i = 0; i < n; i++)
            cout << q[i] << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}