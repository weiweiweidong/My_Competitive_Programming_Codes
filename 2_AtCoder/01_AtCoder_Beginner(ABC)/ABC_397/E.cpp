// Problem: https://atcoder.jp/contests/abc397/tasks/abc397_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int NK = 2e5 + 10;

vector<int> G[NK];
int n, k, sz[NK];

// 输出 No 并直接结束程序
void NO() {
    cout << "No" << endl;
    // 直接结束程序
    exit(0);
}

void dfs(int u, int fa) {
    sz[u] = 1;
    int son = 0;
    // 遍历 u 的所有子节点
    for (int v : G[u])
        if (v != fa) {
            dfs(v, u);
            // 如果子节点尺寸还有剩余
            if (sz[v]) {
                son++;
                sz[u] += sz[v];
            }
        }

    // 如果 sz[u]<k，说明此时 u 只能形成单链结构
    if (sz[u] < k) {
        // 如果 u 是根节点 或 u 有超过 2 个儿子
        if (u == 1 || son > 1)
            NO();
    }
    // 如果 sz[u]==k，说明此时 u 可以有两个儿子
    else if (sz[u] == k) {
        if (son > 2)
            NO();
        // 清空该子树
        sz[u] = 0;
    }
    // 如果 sz[u]>k，没有符合条件的路径
    else
        NO();
}

void solve() {
    // 读入数据 并 建图
    cin >> n >> k;
    for (int i = 1; i < n * k; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v), G[v].push_back(u);
    }

    // 1号节节点为根节点，0为虚拟父节点
    dfs(1, 0);

    cout << "Yes" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}