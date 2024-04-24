// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10, M = N * 3;
int h[N], e[M], ne[M], idx;
bool st[N];
bool edge_st[M];
int n, m;
LL res;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

// 计算当前联通块内有多少个点
void bfs(int x) {
    LL point_num = 1;
    queue<int> q;
    st[x] = true;
    q.push(x);

    while (q.size()) {
        int now = q.front();
        q.pop();
        // 遍历从now伸出去的所有条边
        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            if (!st[next]) {
                point_num++;
                st[next] = true;
                q.push(next);
            }
        }
    }

    // 计算联通块内可以有多少条边
    res += point_num * (point_num - 1) / 2;
}

void solve() {
    // 初始化
    memset(h, -1, sizeof h);
    memset(st, false, sizeof st);
    // 建图
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    // 逐个点遍历
    for (int i = 1; i <= n; i++) {
        // 如果i点没碰过，算一下
        if (!st[i])
            bfs(i);
    }

    // 输出结果
    cout << res - m << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}