// Problem: https://www.acwing.com/problem/content/854/
// SPFA 判断图中是否存在负环
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010, M = 1e4 + 10;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

bool SPFA() {
    // 这道题里dist的初始化可以省掉，因为dist内部的值不论如何更新，不会改变负环的性质
    // memset(dist, 0x3f, sizeof dist);
    queue<int> q;

    // 题目问的是存不存在负环，不是存不存在从1开始的负环
    // 所以这里把所有点都加进去，所有节点都可以是起点
    for (int i = 1; i <= n; i++) {
        st[i] = true;
        q.push(i);
    }

    while (q.size()) {
        int now = q.front();
        q.pop();
        st[now] = false;
        // 看一下和 now 相连的所有节点
        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            // 更新距离，同时更新 cnt
            if (dist[next] > dist[now] + w[i]) {
                dist[next] = dist[now] + w[i];
                cnt[next] = cnt[now] + 1;

                if (cnt[next] >= n)
                    return true;
                // 如果next不在队列里了，就把它加回去
                if (!st[next]) {
                    q.push(next);
                    st[next] = true;
                }
            }
        }
    }
    return false;
}

void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    if (SPFA())
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