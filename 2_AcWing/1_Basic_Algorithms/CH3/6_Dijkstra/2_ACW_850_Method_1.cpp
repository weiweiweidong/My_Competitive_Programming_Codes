// Problem: https://www.acwing.com/problem/content/852/
// 堆优化版 dijkstra，邻接表为数组模拟
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int n, m;
int h[N], ne[N], e[N], w[N], idx;  // 邻接表
int dist[N];
bool st[N];

// 一条从a指向b，权重为c的边
void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    // 声明一个小根堆
    priority_queue<PII, vector<PII>, greater<PII>> heap;

    dist[1] = 0;
    heap.push({0, 1});  // 格式为： 距离 vs 点编号

    while (heap.size()) {
        // 取出距离最小的点
        auto now = heap.top();
        heap.pop();
        int now_index = now.second, now_dist = now.first;
        // 如果这个点已经被用过了，就跳过
        if (st[now_index])
            continue;
        st[now_index] = true;
        // 看所有邻接的点，能否被更新距离
        for (int i = h[now_index]; i != -1; i = ne[i]) {
            int next_index = e[i];
            if (dist[next_index] > now_dist + w[i]) {
                dist[next_index] = now_dist + w[i];
                heap.push({dist[next_index], next_index});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << dijkstra() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}