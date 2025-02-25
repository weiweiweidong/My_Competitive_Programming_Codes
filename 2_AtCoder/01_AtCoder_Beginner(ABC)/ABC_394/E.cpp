// Problem: https://atcoder.jp/contests/abc394/tasks/abc394_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9 + 10;

void solve() {
    int n;
    cin >> n;
    vector<vector<char>> c(n, vector<char>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> c[i][j];

    vector<vector<int>> a(n, vector<int>(n, INF));

    queue<PII> q;

    // 对角线的点全部放入栈内
    for (int i = 0; i < n; i++) {
        q.push({i, i});
        a[i][i] = 0;
    }

    // 读入所有的边
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i == j || c[i][j] == '-')
                continue;
            q.push({i, j});
            a[i][j] = 1;
        }

    while (q.size()) {
        auto now = q.front();
        q.pop();
        int i = now.first, j = now.second;

        for (int k = 0; k < n; k++)
            for (int l = 0; l < n; l++) {
                if (c[k][i] != '-' && c[j][l] != '-' && c[k][i] == c[j][l] &&
                    a[k][l] == INF) {
                    a[k][l] = a[i][j] + 2;
                    q.push({k, l});
                }
            }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (a[i][j] == INF ? -1 : a[i][j]) << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}