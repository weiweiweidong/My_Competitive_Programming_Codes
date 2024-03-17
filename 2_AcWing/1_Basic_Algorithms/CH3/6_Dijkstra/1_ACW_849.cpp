// Problem: https://www.acwing.com/problem/content/851/
// 朴素版 Dijkstra 算法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 510;
int n, m;
int g[N][N];  // 邻接矩阵（初始值正无穷）
int dist[N];  // 存储1点到i点的最短距离（初始值正无穷）
bool st[N];   // 看每个节点是否被用掉

int dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    // 1点到1点的距离为0
    dist[1] = 0;

    // 遍历n遍
    for (int i = 0; i < n; i++) {
        // 设当前要看的节点为 -1
        int now = -1;
        // 遍历一遍所有的点，找到目前状态下，距离最短的点
        // <-- 这一步找最小值的过程，就是朴素版dijkstra算法中最慢的地方
        for (int next = 1; next <= n; next++) {
            if (!st[next] && (now == -1 || dist[now] > dist[next]))
                now = next;
        }

        // 把这个点标记为已用
        st[now] = true;
        // 遍历一遍所有点，更新最短距离
        for (int next = 1; next <= n; next++) {
            dist[next] = min(dist[next], dist[now] + g[now][next]);
        }
    }

    // 如果距离为正无穷，输出-1
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    // 输出最短距离
    return dist[n];
}

void solve() {
    memset(g, 0x3f, sizeof g);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = min(g[a][b], c);
    }
    cout << dijkstra() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}