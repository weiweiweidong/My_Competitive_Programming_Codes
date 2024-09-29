// Problem: https://www.acwing.com/problem/content/1029/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 15;
int n;
int w[N][N];
int f[N * 2][N][N];

void solve() {
    // 读入数据
    cin >> n;
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c)
        w[a][b] = c;

    // DP
    for (int k = 2; k <= n + n; k++) {
        for (int i1 = 1; i1 <= n; i1++) {
            for (int i2 = 1; i2 <= n; i2++) {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n) {
                    int weight = w[i1][j1];
                    if (i1 != i2)
                        weight += w[i2][j2];
                    int& x = f[k][i1][i2];
                    x = max(x, f[k - 1][i1 - 1][i2 - 1] + weight);
                    x = max(x, f[k - 1][i1 - 1][i2] + weight);
                    x = max(x, f[k - 1][i1][i2 - 1] + weight);
                    x = max(x, f[k - 1][i1][i2] + weight);
                }
            }
        }
    }

    cout << f[n + n][n][n] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}