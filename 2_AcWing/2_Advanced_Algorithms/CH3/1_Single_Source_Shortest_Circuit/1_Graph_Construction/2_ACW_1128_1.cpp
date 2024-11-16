// Problem: https://www.acwing.com/problem/content/1130/

// 使用 Dijkstra 算法，使用邻接表构建图
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, M = 440;
int n, m;
int h[N], w[M], e[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int now = t.second, distance = t.first;
        if (st[now])
            continue;
        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            if (dist[next] > distance + w[i]) {
                dist[next] = distance + w[i];
                heap.push({dist[next], next});
            }
        }
    }
}

void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dijkstra();

    int res = -1;
    for (int i = 1; i <= n; i++)
        res = max(res, dist[i]);

    // 如果 res 很大，说明并没有被更新到，是孤立点
    if (res > 2e5)
        res = -1;
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}