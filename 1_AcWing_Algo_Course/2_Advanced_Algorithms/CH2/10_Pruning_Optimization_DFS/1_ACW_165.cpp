// Problem: https://www.acwing.com/problem/content/167/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 20;
int w[N];
int sum[N];
int n, m;
int res = N;

void dfs(int u, int group) {
    // 最优性剪枝
    if (group > res)
        return;
    if (u == n) {
        res = group;
        return;
    }

    // 看这一个物品可以放在哪个组里
    for (int i = 0; i < group; i++)
        // 可行性剪枝
        if (sum[i] + w[u] <= m) {
            sum[i] += w[u];
            dfs(u + 1, group);  // 向下走
            sum[i] -= w[u];     // 恢复现场
        }

    // 或者新开一个组
    {
        sum[group] = w[u];
        dfs(u + 1, group + 1);
        sum[group] = 0;
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> w[i];

    // 按照物品重量从大到小排序
    /*
        这是一个优化策略。
        优势在于：
            可以更早剪枝：大物品更难组合，提前处理可以更快地确定最少组数，减少搜索树分支数量
    */
    sort(w, w + n);
    reverse(w, w + n);

    dfs(0, 0);
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}