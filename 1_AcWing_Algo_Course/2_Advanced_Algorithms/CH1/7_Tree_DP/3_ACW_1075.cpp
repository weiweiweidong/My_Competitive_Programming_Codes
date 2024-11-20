// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 500010, M = N;
int n;
int h[N], e[M], w[M], ne[M], idx;
int sum[N];
bool st[N];
int ans;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// dfs：求出u点的最远距离
int dfs(int u) {
    st[u] = true;

    int dist = 0;  // 存储u的子节点能向外延伸的最远距离
    int d1 = 0, d2 = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            int d = dfs(j);
            dist = max(dist, d);
            // 更新一下u能延伸的最远和次远距离
            if (d >= d1)
                d2 = d1, d1 = d;
            else if (d > d2)
                d2 = d;
        }
    }
    ans = max(ans, d1 + d2);
    return dist + 1;
}

void solve() {
    cin >> n;
    memset(h, -1, sizeof h);

    // 快速求出每个数的约数和
    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= n / i; j++)
            sum[i * j] += i;

    // 建有向图
    /*
        备注：
        答案一定是一个以1为根的子树。（直觉判断，不会证明）
        可以建双向边。但是每次dfs都是从根1节点开始，有根数的直径一定会经过根节点。
        前面的题目求树的直径建无向边，是因为不确定该点一定是根节点。但本题目可以确定1就是根节点。
    */
    for (int i = 2; i <= n; i++)
        if (sum[i] < i)
            add(sum[i], i);

    // 对每个点 dfs
    for (int i = 1; i <= n; i++)
        if (!st[i])
            dfs(i);

    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}