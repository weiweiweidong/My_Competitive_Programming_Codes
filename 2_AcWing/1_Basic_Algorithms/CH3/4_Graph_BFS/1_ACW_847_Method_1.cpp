// Problem: https://www.acwing.com/problem/content/849/
// BFS 求图的最短距离
// 数组模拟临界表，数组模拟队列

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

void BFS() {
    memset(d, -1, sizeof d);
    d[1] = 0;
    q[0] = 1;

    while (hh <= tt) {
        int now = q[hh++];
        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            if (d[next] == -1) {
                d[next] = d[now] + 1;
                q[++tt] = next;
            }
        }
    }
}

void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    BFS();
    cout << d[n] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}