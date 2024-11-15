// Problem: https://www.acwing.com/problem/content/1131/

// Dijkstra 算法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2510, M = 2 * 6200 + 10;
int n, m, start, ed;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int now = t.second, distance = t.first;

        if (st[now])
            continue;
        st[now] = true;

        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            if (dist[next] > distance + w[i]) {
                dist[next] = distance + w[i];
                heap.push({dist[next], next});
            }
        }
    }

    if (dist[ed] == 0x3f3f3f)
        return -1;
    return dist[ed];
}

void solve() {
    memset(h, -1, sizeof h);

    cin >> n >> m >> start >> ed;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    cout << dijkstra() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}