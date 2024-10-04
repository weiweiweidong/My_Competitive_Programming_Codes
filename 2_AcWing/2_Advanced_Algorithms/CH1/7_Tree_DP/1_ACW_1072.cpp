// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10010, M = N * 2;  // N节点数，M边数
int n;
int h[N], e[M], w[M], ne[M], idx;
int ans;

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

// father表示u的父节点。无向图，且迭代过程中不能回到父节点，需要特殊标记
int dfs(int u, int father) {
    int dist = 0;
    int d1 = 0, d2 = 0;

    // 遍历u的所有邻边
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];  // j是下一个节点
        if (j == father)
            continue;
        int d = dfs(j, u) + w[i];  // 求出路径的长度
        dist = max(dist, d);

        // d1,d2求出以该点为顶点的最长路径
        if (d >= d1)
            d2 = d1, d1 = d;  // d1最长路径, d2次长路径
        else if (d > d2)
            d2 = d;
    }

    // 以顶点u的最长路径
    ans = max(ans, d1 + d2);
    return dist;  // 返回当前点的f[x];
}

void solve() {
    cin >> n;
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs(1, -1);
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}