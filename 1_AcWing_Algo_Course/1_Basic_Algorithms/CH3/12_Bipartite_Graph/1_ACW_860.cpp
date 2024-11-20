// Problem: https://www.acwing.com/problem/content/862/
// 染色法判断二分图，DFS实现
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 2e5 + 10;
int n, m;
int h[N], ne[M], e[M], idx;
int color[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool dfs(int u, int c) {
    // 给这个点染成c颜色
    color[u] = c;
    // 看一下下一个点
    for (int i = h[u]; i != -1; i = ne[i]) {
        int next = e[i];
        // 如果下一个点没被染色
        if (!color[next]) {
            // 看能不能被染成下一种颜色
            // 技巧：3-c
            // 能够保证，上一点为1，下一点为2；或者上一点为2，下一点为1
            if (!dfs(next, 3 - c))
                return false;
        }
        // 如果下一个点被染色了，并且已经染成c颜色
        else if (color[next] == c)
            return false;
    }
    return true;
}

void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}