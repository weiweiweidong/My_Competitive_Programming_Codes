// Problem: https://www.acwing.com/problem/content/855/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 510, M = 1e4 + 10;
int n, m, k;
struct Edge {
    int a, b, w;
} edges[M];
int dist[N], last[N];

void bellman_ford() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i++) {
        memcpy(last, dist, sizeof dist);
        for (int j = 0; j < m; j++) {
            auto e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.w);
        }
    }
}

void solve() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    bellman_ford();

    if (dist[n] > 0x3f3f3f3f / 2)
        cout << "impossible" << endl;
    else
        cout << dist[n] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}