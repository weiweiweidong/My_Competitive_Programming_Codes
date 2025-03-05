// Problem: https://atcoder.jp/contests/abc395/tasks/abc395_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

// G[u]：存储所有以 u 为起点的边的信息，(v,w)： u->v，边权为 w
vector<PII> G[N * 2];
int n, m, x;

LL dis[N * 2];
bool used[N * 2];

void addedge(int u, int v, int w) {
    G[u].emplace_back(v, w);
}

void solve() {
    cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        // 正向建图
        addedge(u, v, 1);
        // 反向建图
        addedge(v + n, u + n, 1);
    }
    // 在正图和反图的节点之间添加边权为 x 的双向边
    for (int i = 1; i <= n; i++) {
        addedge(i, i + n, x);
        addedge(i + n, i, x);
    }

    /* 堆优化版的 Dijkstra 模板*/
    // 小根堆
    priority_queue<pair<LL, int>, vector<pair<LL, int>>, greater<pair<LL, int>>>
        q;
    for (int i = 1; i <= 2 * n; i++)
        dis[i] = 1e18;
    q.push({dis[1] = 0, 1});
    while (!q.empty()) {
        auto [_, v] = q.top();
        q.pop();
        used[v] = true;

        for (auto [to, w] : G[v]) {
            if (dis[to] > dis[v] + w) {
                dis[to] = dis[v] + w;
                q.push({dis[to], to});
            }
        }
    }

    cout << min(dis[n], dis[n + n]) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}