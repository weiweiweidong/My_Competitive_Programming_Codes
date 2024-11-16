// Problem: https://www.acwing.com/problem/content/1129/

// Dijkstra 算法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 810, M = 3000;
int n, m, t;
int num[N];
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
LL res = 0x3f3f3f3f3f3f3f3f;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

void dijkstra(int start) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
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
}

void solve() {
    // 初始化
    memset(h, -1, sizeof h);
    // 读入：奶牛数量，节点数，边数
    cin >> t >> n >> m;
    // 读入奶牛位置
    for (int i = 1; i <= t; i++) {
        int x;
        cin >> x;
        num[x]++;
    }

    // 构建图
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    // 遍历每个点作为起点
    for (int i = 1; i <= n; i++) {
        // 以 i 为起点算单源最短路
        dijkstra(i);

        LL cost = 0;
        // 枚举每个点作为终点
        for (int j = 1; j <= n; j++) {
            cost += (LL)dist[j] * num[j];
        }

        res = min(res, cost);
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}