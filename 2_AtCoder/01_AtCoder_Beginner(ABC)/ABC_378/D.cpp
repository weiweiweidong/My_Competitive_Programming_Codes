// Problem: https://atcoder.jp/contests/abc378/tasks/abc378_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 15;
string g[N];    // 存储网格
bool st[N][N];  // 存储遍历状态
int n, m, k;
int res;
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int k) {
    if (k == 0) {
        res++;
        return;
    }

    for (int i = 0; i < 4; i++) {
        int a = x + dx[i], b = y + dy[i];

        if (a < 1 || a > n || b < 1 || b > m)
            continue;
        if (g[a][b] == '#' || st[a][b])
            continue;

        st[a][b] = true;
        dfs(a, b, k - 1);
        st[a][b] = false;
    }
}

void solve() {
    // 读入数据，1-base
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        cin >> g[i];
        g[i] = " " + g[i];
    }

    // 对于每个点都 DFS 一遍
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (g[i][j] == '#')
                continue;

            st[i][j] = true;
            dfs(i, j, k);
            st[i][j] = false;
        }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}