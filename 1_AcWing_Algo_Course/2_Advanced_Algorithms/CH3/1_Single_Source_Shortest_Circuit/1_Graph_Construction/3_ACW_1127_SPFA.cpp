// Problem: https://www.acwing.com/problem/content/1129/

// SPFA 算法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 810, M = 3000;
int n, m, t;
int num[N];
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
bool st[N];
LL res = 0x3f3f3f3f3f3f3f3f;

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

void spfa(int start) {
    memset(dist, 0x3f, sizeof dist);
    dist[start] = 0;
    queue<int> q;
    q.push(start);
    st[start] = true;

    while (q.size()) {
        int now = q.front();
        q.pop();
        st[now] = false;

        for (int i = h[now]; i != -1; i = ne[i]) {
            int next = e[i];
            if (dist[next] > dist[now] + w[i]) {
                dist[next] = dist[now] + w[i];
                if (!st[next]) {
                    q.push(next);
                    st[next] = true;
                }
            }
        }
    }
}

void solve() {
    memset(h, -1, sizeof h);

    cin >> t >> n >> m;
    for (int i = 1; i <= t; i++) {
        int x;
        cin >> x;
        num[x]++;
    }

    for (int i = 1; i <= m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    for (int i = 1; i <= n; i++) {
        spfa(i);

        LL cost = 0;
        for (int i = 1; i <= n; i++)
            cost += (LL)dist[i] * num[i];

        res = min(res, cost);
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}