// Problem: https://www.acwing.com/problem/content/5563/
// 倍增法求LCA
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10, K = 20;

int n, m;
int fa[N][K], dep[N];

// 查询最低公共祖先
int lca(int a, int b) {
    // 把深度更深的放前面
    if (dep[a] < dep[b])
        swap(a, b);
    // 逐步把a向上移动，直到a和b在同一深度
    for (int k = K - 1; k >= 0; k--)
        if (dep[fa[a][k]] >= dep[b])
            a = fa[a][k];
    // 如果他们是同一节点了，就直接返回
    if (a == b)
        return a;
    // 把a和b一起向上翻，直到相遇
    for (int k = K - 1; k >= 0; k--)
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    return fa[a][0];
}

int get_dist(int a, int b) {
    // 找到最低公共祖先
    int p = lca(a, b);
    // 返回两点间的距离
    return dep[a] + dep[b] - dep[p] * 2;
}

int main() {
    scanf("%d", &m);

    for (int i = 2; i <= 4; i++)
        fa[i][0] = 1, dep[i] = 1;
    n = 4;

    int A = 2, B = 3, res = 2;

    while (m--) {
        int u;
        scanf("%d", &u);
        int x = n + 1, y = n + 2;
        n += 2;

        dep[x] = dep[y] = dep[u] + 1;
        fa[x][0] = fa[y][0] = u;

        for (int k = 1; k < K; k++) {
            fa[x][k] = fa[fa[x][k - 1]][k - 1];
            fa[y][k] = fa[fa[y][k - 1]][k - 1];
        }

        int da = get_dist(A, x), db = get_dist(B, x);
        if (da > db && da > res)
            res = da, B = x;
        else if (da <= db && db > res)
            res = db, A = x;

        printf("%d\n", res);
    }

    return 0;
}