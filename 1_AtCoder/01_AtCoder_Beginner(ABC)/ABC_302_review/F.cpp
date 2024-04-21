// Problem: https://atcoder.jp/contests/abc302/tasks/abc302_f
/*
    二分图的构建 + 图的最短路径BFS
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 4e5 + 10;
vector<int> graph[MAXN];
int dist[MAXN];
int n, m, a, x;

int bfs() {
    memset(dist, -1, sizeof dist);
    dist[n + 1] = 0;
    queue<int> q;
    q.push(n + 1);

    while (q.size()) {
        int now = q.front();
        q.pop();
        for (auto next : graph[now]) {
            if (dist[next] == -1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }

            if (next == n + m)
                break;
        }
    }
    return dist[n + m];
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        for (int j = 1; j <= a; j++) {
            cin >> x;
            graph[i].push_back(n + x);
            graph[n + x].push_back(i);
        }
    }
    int res = bfs();

    if (res != -1)
        res = res / 2 - 1;
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}