// Problem: https://www.acwing.com/problem/content/861/
// Kruskal 算法求最小生成树（适用于稀疏图）
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
int n, m;
struct Edges {
    int a, b, w;
    bool operator<(const Edges& W) const { return w < W.w; }
} edges[M];
int p[N];

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int Kruskal() {
    // 并查集初始化
    for (int i = 1; i <= n; i++)
        p[i] = i;
    // 按照边权，升序排序
    sort(edges, edges + m);

    int res = 0, cnt = 0;
    // 遍历所有的边
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        // 如果a和b不在同一个集合内
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1)
        return INF;
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }

    int res = Kruskal();
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