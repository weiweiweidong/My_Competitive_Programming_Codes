// Problem: https://atcoder.jp/contests/abc378/tasks/abc378_f

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10, M = 4e5 + 10;
int h[N], e[M], ne[M], idx;  // 存储图
int n;
int deg[N];  // 记录度数
bool st[N];  // 记录是否被看过
int cnt;     // 记录点的数量
LL res;      // 记录结果

// 建图加边
void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// DFS
void dfs(int now, int fa = 0) {
    // 如果当前点度数不为 3
    if (deg[now] != 3) {
        // 如果度数是 2，就计数
        cnt += (deg[now] == 2);
        return;
    }

    // 此点标记
    st[now] = true;
    // 看一下周围的点
    for (int i = h[now]; i != -1; i = ne[i]) {
        int next = e[i];
        // 如果是来时的点就跳过
        if (next == fa)
            continue;
        // 向下搜
        dfs(next, now);
    }
}

void solve() {
    // h 数组初始化
    memset(h, -1, sizeof h);

    // 读入数据，同时预处理各个节点的度数
    cin >> n;
    for (int i = 1; i <= n - 1; i++) {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
        deg[u]++, deg[v]++;
    }

    // 依次遍历每个节点
    for (int i = 1; i <= n; i++) {
        // 度数不为 3，直接跳过
        if (deg[i] != 3)
            continue;
        // 如果这个点已经看过了，跳过
        if (st[i])
            continue;

        // 计算当前连通块，周围度数为 2 的点的数量
        cnt = 0;
        dfs(i);
        res += 1ll * cnt * (cnt - 1) / 2;
    }

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}