// Problem: https://www.acwing.com/problem/content/1173/
// Tarjan 法求LCA
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10010, M = N * 2;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
int p[N];
int res[M];            // 存储每个询问的结果
int st[N];             // 标记数组
vector<PII> query[N];  // first存查询的另外一个点，second存查询编号

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

// 向下遍历，预处理出来距离
void dfs(int now, int fa) {
    // 遍历 now 的所有的临点
    for (int i = h[now]; ~i; i = ne[i]) {
        int next = e[i];
        if (next == fa)
            continue;
        // 更新子节点的距离
        dist[next] = dist[now] + w[i];
        dfs(next, now);
    }
}

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void tarjan(int now) {
    st[now] = 1;  // 标记这个点正在搜
    // 看now周围的点
    for (int i = h[now]; ~i; i = ne[i]) {
        int next = e[i];
        // 如果next点完全没被搜过
        if (!st[next]) {
            // 向下搜
            tarjan(next);
            // 把next点的祖宗标记为 now
            p[next] = now;
        }
    }

    // 遍历所有和 now 相关的查询
    for (auto item : query[now]) {
        int y = item.first, id = item.second;

        // 如果y点已经搜完并回溯过
        if (st[y] == 2) {
            int anc = find(y);  // 找y的祖宗节点
            res[id] = dist[now] + dist[y] - dist[anc] * 2;  // 计算两点间的距离
        }
    }
    // 标记now点搜过并且回溯过
    st[now] = 2;
}

int main() {
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    // 存储所有的边
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }
    // 存储m个查询
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a != b) {
            query[a].push_back({b, i});  // 和a相关的另一个点是b，查询编号是i
            query[b].push_back({a, i});  // 和b相关的另一个点是a，查询编号是i
        }
    }

    // 并查集初始化
    for (int i = 1; i <= n; i++)
        p[i] = i;

    // 预处理 dist，求每个点和根节点之间的距离
    dfs(1, -1);
    tarjan(1);

    // 输出每一个询问
    for (int i = 0; i < m; i++)
        printf("%d\n", res[i]);

    return 0;
}