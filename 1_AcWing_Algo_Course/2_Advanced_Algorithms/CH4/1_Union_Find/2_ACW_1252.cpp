// Problem: https://www.acwing.com/problem/content/1254/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10010;
int n, m, vol;
int p[N];
int v[N], w[N];  // v:物品的价格; w:物品的价值
int f[N];        // 01 背包的 DP

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void solve() {
    cin >> n >> m >> vol;
    // 并查集初始化
    for (int i = 0; i <= n; i++)
        p[i] = i;
    // 读入每件物品的价格和价值
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i];
    // 读入搭配数据
    while (m--) {
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        // 当祖宗节点不同时，做合并运算
        if (pa != pb) {
            v[pb] += v[pa];  // pa的体积加到pb上
            w[pb] += w[pa];  // pa的价值加到pb上
            p[pa] = pb;      // 把pb作为pa的祖宗
        }
    }

    // 01 背包
    for (int i = 1; i <= n; i++)
        // 只对根节点做背包
        if (p[i] == i)
            for (int j = vol; j >= v[i]; j--)
                f[j] = max(f[j], f[j - v[i]] + w[i]);

    cout << f[vol] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}