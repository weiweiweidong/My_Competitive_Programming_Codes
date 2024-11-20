// Problem: https://www.acwing.com/problem/content/173/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1 << 24;

int n, m;        // 物品总数，背包容量
int k;           // 用于分治，等于n/2
int g[50];       // 存储每个物品的重量
int weights[N];  // 存储第一组物品的所有可能得重量组合
int cnt;         // 存储 weights 的有效长度
int res;         // 存储结果

// 处理前 k 个物品重量的组合可能性
// u：表示要处理第几个物品
// s：当前已选物品的重量和
void dfs(int u, int s) {
    // 已经到了最后一个物品
    if (u == k) {
        // 记录当前组合的重量
        weights[cnt++] = s;
        return;
    }

    // 选择当前物品（不超过背包容量的前提下）
    if ((LL)s + g[u] <= m)
        // 向下继续搜
        dfs(u + 1, s + g[u]);

    // 不选择当前物品，向下继续搜
    dfs(u + 1, s);
}

// 处理后面的 n-k 个物品
void dfs2(int u, int s) {
    // 如果处理完所有物品了，就在 weights 中二分查找与当前 s 组合的最大重量
    if (u == n) {
        int l = 0, r = cnt - 1;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (weights[mid] + (LL)s <= m)
                l = mid;
            else
                r = mid - 1;
        }

        // 更新答案
        if (weights[l] + (LL)s <= m)
            res = max(res, weights[l] + s);
        return;
    }

    // 选择当前物品（在不超过背包容量的前提下）
    if ((LL)s + g[u] <= m)
        dfs2(u + 1, s + g[u]);
    // 不选择当前物品
    dfs2(u + 1, s);
}

void solve() {
    // 读入物品数量 和 背包容量
    cin >> m >> n;

    // 读入每个物品的重量
    for (int i = 0; i < n; i++)
        cin >> g[i];

    // 对物品重量降序排列
    sort(g, g + n);
    reverse(g, g + n);

    // 物品分成两组
    k = n / 2;

    // 第一次 dfs，处理前 k 个物品的所有组合
    dfs(0, 0);

    // 对第一组的所有组合可能性排序和去重
    sort(weights, weights + cnt);
    int t = 1;
    for (int i = 1; i < cnt; i++)
        if (weights[i] != weights[i - 1])
            weights[t++] = weights[i];
    cnt = t;

    // 第二次 dfs，处理后面的物品
    dfs2(k, 0);

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}