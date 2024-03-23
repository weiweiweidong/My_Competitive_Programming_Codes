// Problem: https://atcoder.jp/contests/abc303/tasks/abc303_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 55;
int g[N][N];
int n, m;
int A[N][N];

void solve() {
    memset(g, -1, sizeof g);
    cin >> n >> m;

    while (m--) {
        int last = -1;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (i == 1)
                last = x;
            else {
                g[last][x] = 1;
                g[x][last] = 1;
                last = x;
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++) {
            if (g[i][j] == -1)
                res++;
        }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}