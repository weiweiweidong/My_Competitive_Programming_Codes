// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10, M = (1 << 10);

int n, m;
int g[1010];
int f[2][M][M];
vector<int> state;
int cnt[M];

bool check(int st) {
    return !(st & (st >> 1) || st & (st >> 2));
}

int count(int st) {
    int res = 0;
    for (int i = 0; i < m; i++)
        res += (st >> i & 1);
    return res;
}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            g[i] += (c == 'H') << j;
        }

    for (int i = 0; i < (1 << m); i++)
        if (check(i)) {
            state.push_back(i);
            cnt[i] = count(i);
        }

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < state.size(); j++)
            for (int k = 0; k < state.size(); k++)
                for (int u = 0; u < state.size(); u++) {
                    int a = state[j], b = state[k], c = state[u];
                    if (a & b | a & c | b & c)
                        continue;
                    if (g[i] & b | g[i - 1] & a)
                        continue;
                    // 使用滚动数组优化
                    f[i & 1][j][k] =
                        max(f[i & 1][j][k], f[i - 1 & 1][u][j] + cnt[b]);
                }

    int res = 0;
    for (int i = 0; i < state.size(); i++)
        for (int j = 0; j < state.size(); j++)
            res = max(res, f[n & 1][i][j]);

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}