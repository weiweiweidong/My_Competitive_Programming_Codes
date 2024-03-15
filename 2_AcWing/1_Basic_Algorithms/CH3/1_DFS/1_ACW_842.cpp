// Problem: https://www.acwing.com/problem/content/844/
// 最简单的 DFS 示例
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 10;
int path[N];
bool st[N];
int n;

void DFS(int u) {
    if (u == n) {
        for (int i = 0; i < n; i++)
            cout << path[i] << " ";
        cout << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!st[i]) {
            st[i] = true;
            path[u] = i;
            DFS(u + 1);
            st[i] = false;
        }
    }
}

void solve() {
    cin >> n;
    DFS(0);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}