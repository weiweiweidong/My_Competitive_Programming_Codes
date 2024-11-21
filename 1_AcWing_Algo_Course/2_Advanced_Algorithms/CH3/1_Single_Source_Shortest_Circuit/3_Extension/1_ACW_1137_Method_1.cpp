// Problem: https://www.acwing.com/problem/content/1139/

// 思路 1：虚拟原点 + Dijkstra/SPFA

// 注意：本题的输入比较奇葩，在本地无法正常结束程序，需要去在线测评
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010, M = 2e5 + 10;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
int n, m, s;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra() {
    // 初始化
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    // 虚拟原点为 0
    dist[0] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 0});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();
        int now = t.second, distance = t.first;
        if (st[now])
            continue;
        st[now] = true;

        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            if (dist[next] > dist[now] + w[i]) {
                dist[next] = dist[now] + w[i];
                heap.push({dist[next], next});
            }
        }
    }
}

void solve() {
    while (scanf("%d%d%d", &n, &m, &s) != -1) {
        // 邻接表初始化
        memset(h, -1, sizeof h);
        idx = 0;

        // 建图
        while (m--) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }

        // 虚拟原点建图
        // 虚拟原点为 0，建 0->x 边权为 0 的虚拟边
        int cnt;
        scanf("%d", &cnt);
        int x;
        for (int i = 0; i < cnt; i++) {
            scanf("%d", &x);
            // 构建虚拟原点到起点的边
            add(0, x, 0);
        }

        // 求最短路
        dijkstra();

        // 输出结果
        if (dist[s] == 0x3f3f3f3f)
            cout << -1 << endl;
        else
            cout << dist[s] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}