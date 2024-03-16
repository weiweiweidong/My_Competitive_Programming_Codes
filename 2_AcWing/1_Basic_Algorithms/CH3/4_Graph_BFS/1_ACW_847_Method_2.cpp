// Problem: https://www.acwing.com/problem/content/849/
// BFS 求图的最短距离
// vector模拟临界表，STL队列

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m;
queue<int> q;
vector<int> graph[N];
int d[N];

void BFS() {
    memset(d, -1, sizeof d);
    q.push(1);
    d[1] = 0;

    while (q.size()) {
        int now = q.front();
        q.pop();
        for (auto next : graph[now]) {
            if (d[next] == -1) {
                q.push(next);
                d[next] = d[now] + 1;
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    BFS();
    cout << d[n] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}