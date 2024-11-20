// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010;

int n, m, S, T;
double g[N][N];
double dist[N];
bool st[N];

// 朴素版 dijkstra
void dijkstra() {
    dist[S] = 1;
    // 遍历 n 轮
    for (int i = 1; i <= n; i++) {
        int now = -1;
        // 找最小值
        for (int next = 1; next <= n; next++)
            if (!st[next] && (now == -1 || dist[now] < dist[next]))
                now = next;
        st[now] = true;

        for (int next = 1; next <= n; next++)
            dist[next] = max(dist[next], dist[next] * g[now][next]);
    }
}

void solve() {
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        double z = (100.0 - c) / 100;
        g[a][b] = g[b][a] = max(g[a][b], z);
    }

    cin >> S >> T;

    dijkstra();

    cout << fixed << setprecision(8) << (100 / dist[T]) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}