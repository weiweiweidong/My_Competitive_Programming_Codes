// Problem: https://www.acwing.com/problem/content/287/
// 树形DP
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 6010;
int n;
int h[N], e[N], ne[N], idx;
int happy[N];
int f[N][2];
bool has_fa[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

void DFS(int u) {
    // 初始化：
    // 选择u节点，f[u][1] 初始值就是 u 的happy值
    // 不选择u节点，f[u][0] 初始值就是 0
    f[u][1] = happy[u];

    // 遍历每一个儿子
    for (int i = h[u]; i != -1; i = ne[i]) {
        int son = e[i];
        // 先计算儿子的值
        DFS(son);

        // 根据状态转移，计算u的值
        f[u][1] += f[son][0];
        f[u][0] += max(f[son][1], f[son][0]);
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> happy[i];

    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        add(b, a);         // 添加一条从上司指向下属的边
        has_fa[a] = true;  // 标记a有上司
    }

    // 找到祖宗（最大的领导）
    int root = 1;
    while (has_fa[root])
        root++;

    // 从祖宗节点开始向下找
    DFS(root);

    cout << max(f[root][0], f[root][1]) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}