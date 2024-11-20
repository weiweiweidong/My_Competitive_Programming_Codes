// Problem: https://www.acwing.com/problem/content/853/
// SPFA 求最短路
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, m;
int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];  // st[i] 的用法和前面不一样。此时存储的是i点是否在队列中

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

int SPFA() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;  // 标记1点放进了队列中

    while (q.size()) {
        int now = q.front();
        q.pop();
        st[now] = false;  // 标记now点从队列中取出来了

        // 遍历所有临点
        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            // 如果能更新距离，就更新
            if (dist[next] > dist[now] + w[i]) {
                dist[next] = dist[now] + w[i];
                // 如果next点不在队列里，就把它放进去
                if (!st[next]) {
                    q.push(next);
                    st[next] = true;
                }
            }
        }
    }
    return dist[n];
}

void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    int res = SPFA();
    if (res == 0x3f3f3f3f)
        cout << "impossible";
    else
        cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}