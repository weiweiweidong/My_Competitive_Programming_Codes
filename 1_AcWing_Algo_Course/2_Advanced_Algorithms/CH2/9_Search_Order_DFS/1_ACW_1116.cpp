// Problem: https://www.acwing.com/problem/content/1118/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10;
int n, m;
bool st[N][N];
int res;
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void dfs(int x, int y, int cnt) {
    // 如果走过了所有点
    if (n * m == cnt) {
        res++;
        return;
    }

    st[x][y] = true;
    // 八方向遍历
    for (int i = 0; i < 8; i++) {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || b < 0 || a >= n || b >= m)
            continue;
        if (st[a][b])
            continue;

        dfs(a, b, cnt + 1);
    }
    // 恢复现场
    st[x][y] = false;
}

void solve() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int x, y;
        cin >> x >> y;

        // 初始化
        memset(st, 0, sizeof st);
        res = 0;

        dfs(x, y, 1);
        cout << res << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}