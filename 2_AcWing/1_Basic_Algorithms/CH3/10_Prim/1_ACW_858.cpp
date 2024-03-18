// Problem: https://www.acwing.com/problem/content/860/
// Prim 算法求最小生成树
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];  // 表示x点距离集合的距离
bool st[N];   // 表示x点是否已经被加入集合

int prim() {
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++) {  // 遍历n遍
        // 找到目前离集合最近的点
        int now = -1;
        for (int next = 1; next <= n; next++) {
            if (!st[next] && (now == -1 || dist[now] > dist[next]))
                now = next;
        }

        if (i && dist[now] == INF)
            return INF;
        // 把now点加入集合，并更新res
        if (i)
            res += dist[now];
        st[now] = true;
        // 计算所有的点离集合的距离
        for (int next = 1; next <= n; next++) {
            dist[next] = min(dist[next], g[now][next]);
        }
    }
    return res;
}

void solve() {
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 1; i <= n; i++)
        g[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    int res = prim();

    if (res == INF)
        cout << "impossible" << endl;
    else
        cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}