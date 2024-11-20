// Problem: https://www.acwing.com/problem/content/852/
// 堆优化版 dijkstra，邻接表为vector
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int n, m;
vector<PII> graph[N];
int dist[N];
bool st[N];

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});

    while (heap.size()) {
        auto now = heap.top();
        heap.pop();

        int now_index = now.second, now_dist = now.first;
        if (st[now_index])
            continue;
        st[now_index] = true;
        for (auto [next_index, w] : graph[now_index]) {
            if (dist[next_index] > now_dist + w)
                dist[next_index] = now_dist + w;
            heap.push({dist[next_index], next_index});
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
    cout << dijkstra() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}