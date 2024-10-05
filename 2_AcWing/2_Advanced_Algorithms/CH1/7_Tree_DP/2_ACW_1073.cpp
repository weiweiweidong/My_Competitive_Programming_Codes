// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10010;  // 节点数量上限
const int M = 2 * N;  // 边数上限
const int INF = 0x3f3f3f3f;

int n;
int h[N], e[M], w[M], ne[M], idx;
int d1[N], d2[N];  // 存储从节点u出发往下走，第一和第二长的路径长度
int p1[N];  // 表示向下走的最长路径，要经过哪一个子节点
int up[N];  // 存储从节点u向上走的最长的路径长度
bool is_leaf[N];  // 判断当前节点是否为叶子节点

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

// 向下找最长路径
int dfs_d(int u, int father) {
    d1[u] = d2[u] = -INF;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father)
            continue;
        int d = dfs_d(j, u) + w[i];  // 递归计算子树的最长路径
        // 如果d大于当前找到的最长路径，更新d1，d2；同时记录下 最长路径的子节点
        if (d >= d1[u]) {
            d2[u] = d1[u], d1[u] = d;
            p1[u] = j;
        }
        // 如果d为次长路径，更新d2
        else if (d > d2[u])
            d2[u] = d;
    }

    // 如果u没法向下找，说明是叶子节点
    if (d1[u] == -INF) {
        d1[u] = d2[u] = 0;
        is_leaf[u] = true;
    }

    // 返回以u为顶点的最长路径
    return d1[u];
}

// 找向上的最长路径
/*
    这里的思路有点绕：是通过u，来找j向上的最长路径
*/
void dfs_u(int u, int father) {
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (j == father)
            continue;

        // 如果j是节点u的最长向下路径对应的子节点
        if (p1[u] == j)
            up[j] = max(up[u], d2[u]) + w[i];
        else
            up[j] = max(up[u], d1[u]) + w[i];

        dfs_u(j, u);
    }
}

void solve() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs_d(1, -1);  // 往下走的最长路径
    dfs_u(1, -1);  // 往上走的最长路径

    int res = d1[1];
    for (int i = 1; i <= n; i++)
        if (is_leaf[i])
            res = min(res, up[i]);
        else
            res = min(res, max(d1[i], up[i]));

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}