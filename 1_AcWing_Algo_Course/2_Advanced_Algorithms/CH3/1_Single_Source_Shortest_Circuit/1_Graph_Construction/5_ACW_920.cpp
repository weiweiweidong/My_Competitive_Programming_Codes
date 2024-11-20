// Problem: https://www.acwing.com/problem/content/922/

// BFS
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;
int g[N][N];
int dist[N];
int stop[N];
int n, m;

void bfs() {
    memset(dist, 0x3f, sizeof dist);

    queue<int> q;
    q.push(1);
    dist[1] = 0;

    while (q.size()) {
        int now = q.front();
        q.pop();

        for (int next = 1; next <= n; next++) {
            if (g[now][next] && dist[next] > dist[now] + 1) {
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
}

void solve() {
    cin >> m >> n;

    string line;
    getline(cin, line);  // 读取第一行剩余的换行符
    while (m--) {
        getline(cin, line);       // 读取一行
        stringstream ssin(line);  // 用字符串流处理输入
        int cnt = 0, p;
        while (ssin >> p)  // 读取一条线路的所有站点
            stop[cnt++] = p;

        // 建图
        for (int j = 0; j < cnt; j++)
            for (int k = j + 1; k < cnt; k++)
                g[stop[j]][stop[k]] = true;
    }

    bfs();

    if (dist[n] == 0x3f3f3f3f)
        cout << "NO" << endl;
    else
        cout << max(dist[n] - 1, 0) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}