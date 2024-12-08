// Problem: https://www.acwing.com/problem/content/219/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dout[N];  // 存储各节点的出度
double f[N];

// 加边
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c;
    ne[idx] = h[a], h[a] = idx++;
}

double dp(int u) {
    // 记忆化搜索
    if (f[u] >= 0)
        return f[u];

    f[u] = 0;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        f[u] += (w[i] + dp(j)) / dout[u];
    }
    return f[u];
}

void solve() {
    cin >> n >> m;
    memset(h, -1, sizeof h);

    // 建图，并记录各点的出度
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        dout[a]++;
    }

    memset(f, -1, sizeof f);
    cout << fixed << setprecision(2) << dp(1) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}