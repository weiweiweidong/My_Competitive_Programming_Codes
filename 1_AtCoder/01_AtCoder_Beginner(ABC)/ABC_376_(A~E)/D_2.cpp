// Problem:

/*
    标准做法：
    “1 节点能回到 1 节点” 意味着：(1点能走到节点K)+(反向图K能走到1节点)
    这时问题就转化为 求 1->k的最短路 + k->1的最短路

    本题目定义了结构体，来方便实现两个图的 dijkstra 算法
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int n, m, ans;

struct Graph {
    int h[N], e[N], ne[N], idx = 0;
    int dist[N];
    bool st[N];
    priority_queue<PII, vector<PII>, greater<PII>> heap;

    Graph() { memset(h, -1, sizeof h); }

    void add(int a, int b) { e[idx] = b, ne[idx] = h[a], h[a] = idx++; }

    void dijkstra() {
        memset(dist, 0x3f, sizeof dist);
        dist[1] = 0;
        heap.push({0, 1});

        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            int ver = t.second, d = t.first;
            if (st[ver])
                continue;
            st[ver] = true;
            for (int i = h[ver]; i != -1; i = ne[i]) {
                int next = e[i];
                if (dist[next] > d + 1) {
                    dist[next] = d + 1;
                    heap.push({dist[next], next});
                }
            }
        }
    }
} G1, G2;

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        G1.add(a, b);
        G2.add(b, a);
    }

    G1.dijkstra();
    G2.dijkstra();
    ans = n + 1;

    for (int i = 2; i <= n; i++)
        ans = min(ans, G1.dist[i] + G2.dist[i]);
    if (ans > n)
        cout << -1 << endl;
    else
        cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}