// Problem: https://www.acwing.com/problem/content/1131/

// SPFA 算法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2510, M = 2 * 6200 + 10;
int n, m, start, ed;
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
    cin >> n >> m >> start >> ed;
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    spfa();

    cout << dist[ed] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}