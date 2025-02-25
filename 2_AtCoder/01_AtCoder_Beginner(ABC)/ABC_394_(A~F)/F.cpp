// Problem: https://atcoder.jp/contests/abc394/tasks/abc394_f

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int n;
int u, v;
int d[N];          // 度数
bool vis[N];       // 是否被看过
int f[N][2];       // dp
int res;           // 结果
vector<int> g[N];  // 存储图

void dfs(int u) {
    // 标记已经被看过
    vis[u] = true;
    vector<int> tmp;
    // 遍历 u 的每个子节点
    for (int v : g[u])
        if (d[v] >= 4 && !vis[v]) {
            dfs(v);
            tmp.push_back(f[v][1]);
        }
    // 把子树大小降序排列
    sort(tmp.rbegin(), tmp.rend());
    // 初始化为 1（要包含 u 节点本身）
    f[u][1] = 1;
    // 选最大的三个儿子，加在一起，就是 f[u][1]
    for (int i = 0; i < tmp.size() && i < 3; i++)
        f[u][1] += tmp[i];

    // f[u][0] 相比于 f[u][1]，就是多加了第四大的子树
    f[u][0] = f[u][1];
    if (tmp.size() >= 4)
        f[u][0] += tmp[3];
    // 更新答案
    res = max(res, f[u][0]);
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        // 邻接表建图
        g[u].push_back(v), g[v].push_back(u);
        // 预处理度数
        d[u]++, d[v]++;
    }

    // 遍历每一个点
    for (int i = 1; i <= n; i++) {
        // 如果点 i 度数大于等于 4，并且还没被看过，就向下搜
        if (d[i] >= 4 && !vis[i]) {
            dfs(i);
        }
    }

    // 输出结果
    if (res == 0)
        cout << -1 << endl;
    else
        cout << res * 3 + 2 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}