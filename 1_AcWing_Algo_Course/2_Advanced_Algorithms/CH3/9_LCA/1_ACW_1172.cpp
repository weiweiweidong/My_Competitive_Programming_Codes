// Problem:　https://www.acwing.com/problem/content/1174/
// 倍增法求LCA
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 4e4 + 10, M = N * 2;
int n, m;
int h[N], e[M], ne[M], idx;
int depth[N], fa[N][16];
int q[N];

// 邻接表添加边
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

// BFS构建 fa数组
void bfs(int root) {
    // 所有点的深度设为正无穷
    memset(depth, 0x3f, sizeof depth);
    // 设置0点深度为0，哨兵；root深度为1
    depth[0] = 0, depth[root] = 1;
    // BFS遍历所有边
    int hh = 0, tt = 0;
    q[0] = root;
    while (hh <= tt) {
        int now = q[hh++];
        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            // 如果next点的深度可以被更新
            if (depth[next] > depth[now] + 1) {
                depth[next] = depth[now] + 1;  // 更新next点的深度
                q[++tt] = next;                // next点加入队列
                fa[next][0] = now;             // 更新next点的爹
                // 距离从小到大向上更新祖宗（超出的地方自然而然就是0）
                for (int k = 1; k <= 15; k++)
                    fa[next][k] = fa[fa[next][k - 1]][k - 1];
            }
        }
    }
}

// 求a和b的最近公共祖先
int lca(int a, int b) {
    // 把深的放在前面
    if (depth[a] < depth[b])
        swap(a, b);
    // 从大到小，找到a和b相同的层级
    for (int k = 15; k >= 0; k--)
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    // 如果a和b相同，直接返回a
    if (a == b)
        return a;
    // 否则就同时把a和b向上跳，直到他俩的father相遇
    for (int k = 15; k >= 0; k--)
        if (fa[a][k] != fa[b][k]) {
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

void solve() {
    cin >> n;
    // 把 -1 当作根节点
    int root = -1;
    memset(h, -1, sizeof h);
    // 读入数据，并构建图
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (b == -1)
            root = a;
        else
            add(a, b), add(b, a);
    }
    // bfs创建 fa 数组和 depth 数组
    bfs(root);

    // 读入m个查询
    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        // 找到a和b的最低公共祖先
        int p = lca(a, b);

        // 判断结果
        if (p == a)
            cout << 1 << endl;
        else if (p == b)
            cout << 2 << endl;
        else
            cout << 0 << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}