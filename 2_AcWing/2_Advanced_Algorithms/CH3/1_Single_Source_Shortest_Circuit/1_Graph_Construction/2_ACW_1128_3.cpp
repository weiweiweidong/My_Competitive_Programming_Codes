// Problem: https://www.acwing.com/problem/content/1130/

// SPFA 算法，使用邻接表构建图
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110, M = 440;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

void spfa() {
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    st[1] = true;

    while (q.size()) {
        int now = q.front();
        q.pop();
        st[now] = false;

        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            if (dist[next] > dist[now] + w[i]) {
                dist[next] = dist[now] + w[i];
                if (!st[next]) {
                    st[next] = false;
                    q.push(next);
                }
            }
        }
    }
}

void solve() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    spfa();

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dist[i]);

    if (res >= 2e5)
        res = -1;
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}