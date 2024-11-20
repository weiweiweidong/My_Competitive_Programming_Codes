// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, M = N * 2;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int f[N][N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u, int father) {
    // 遍历所有和u相连的子节点
    for (int i = h[u]; i != -1; i = ne[i]) {
        int next = e[i];
        // 跳过父节点
        if (next == father)
            continue;
        // 递归处理子树
        dfs(next, u);

        // 遍历能够选择的边数
        for (int j = m; j; j--) {
            // 从子节点选择k条边时候的最大权重
            for (int k = 0; k + 1 <= j; k++)
                // 更新的时候，u->next 之间一定会有一条边。
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[next][k] + w[i]);
        }
    }
}

void solve() {
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs(1, -1);

    cout << f[1][m] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}