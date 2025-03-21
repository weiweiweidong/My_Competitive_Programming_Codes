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
    int ch = 0;
    // 遍历 u 的所有子节点
    for (int v : G[u])
        if (v != fa) {
            dfs(v, u);
            // 如果子节点尺寸还有剩余
            if (sz[v]) {
                ch++;
                sz[u] += sz[v];
            }
        }

    if (sz[u] < k) {
        if (u == 1 || ch > 1)
            NO();
    } else if (sz[u] == k) {
        if (ch > 2)
            NO();
        sz[u] = 0;
    } else
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

    dfs(1, 0);

    cout << "Yes" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}