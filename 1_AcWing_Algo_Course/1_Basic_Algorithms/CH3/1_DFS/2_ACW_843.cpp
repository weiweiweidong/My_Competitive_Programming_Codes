// Problem: https://www.acwing.com/problem/content/845/
// 八皇后问题
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10;
int n;
char g[N][N];
bool col[N], dg[2 * N], udg[2 * N];

void DFS(int x) {
    if (x == n) {
        for (int i = 0; i < n; i++)
            cout << g[i] << endl;
        cout << endl;
        return;
    }

    for (int y = 0; y < n; y++) {
        if (!col[y] && !dg[x + y] && !udg[n - x + y]) {
            g[x][y] = 'Q';
            col[y] = dg[x + y] = udg[n - x + y] = true;
            DFS(x + 1);
            g[x][y] = '.';
            col[y] = dg[x + y] = udg[n - x + y] = false;
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            g[i][j] = '.';
    DFS(0);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}