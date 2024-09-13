// Problem: https://atcoder.jp/contests/abc369/tasks/abc369_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAX_N = 405;
const int MAX_M = 2e5 + 10;
LL dist[MAX_N][MAX_N];
int edge[MAX_M][3];  // 分别存入 起始点，终止点，边权
int n, m, q;
int b[10];  // 用于存储每次查询用到的边

void floyd() {
    for (int k = 1; k <= n; k++)          // 遍历中间点
        for (int i = 1; i <= n; i++)      // 遍历起点
            for (int j = 1; j <= n; j++)  // 遍历终点
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);  // 更新
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i == j)
                dist[i][j] = 0;
            else
                dist[i][j] = 1e18;
        }

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i][0] = a, edge[i][1] = b, edge[i][2] = c;
        dist[a][b] = min(dist[a][b], (LL)c);
        dist[b][a] = min(dist[b][a], (LL)c);
    }

    floyd();

    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        LL ans = 1e18;
        for (int i = 0; i < k; i++)
            cin >> b[i];
        // 枚举一个b的全排列
        do {
            // 枚举每个位置是 u->v 还是 v->u
            for (int S = 0; S < (1 << k); ++S) {
                // S的第i个位置是0 ： now -> edge[i][0] -> edge[i][1]
                // S的第i个位置是1 ： now -> edge[i][1] -> edge[i][0]
                // 综合一下：now -> edge[i][S的第i位] -> edge[i][S的第i位取反]
                int now = 1;
                LL D = 0;
                for (int i = 0; i < k; i++) {
                    D += dist[now][edge[b[i]][(S >> i) & 1]];
                    D += (LL)edge[b[i]][2];
                    now = edge[b[i]][!((S >> i) & 1)];
                }
                D += dist[now][n];
                ans = min(ans, D);
            }
        } while (next_permutation(b, b + k));
        cout << ans << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}