// Problem:
/*
BFS 解法：
    本题目可以使用 BFS 的最主要原因是：边权为 1
    如果本题目边权不为 1 的话，就没有办法使用 BFS 了
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9 + 10;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 10);  // 声明图。+10 是为了留余量
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);  // 添加边
    }

    queue<int> q;
    vector<int> dis(n + 10, INF);
    for (auto v : g[1]) {
        q.push(v);
        dis[v] = 1;
    }

    while (!q.empty()) {
        int now = q.front();
        q.pop();

        for (auto next : g[now]) {
            if (dis[next] < dis[now] + 1)
                continue;
            // 更新 next 点的距离
            dis[next] = min(dis[next], dis[now] + 1);
            // 如果遇到了 1，直接退出
            if (next == 1)
                break;
            // 否则把 next 点加入队列
            q.push(next);
        }
    }

    cout << (dis[1] == INF ? -1 : dis[1]) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}