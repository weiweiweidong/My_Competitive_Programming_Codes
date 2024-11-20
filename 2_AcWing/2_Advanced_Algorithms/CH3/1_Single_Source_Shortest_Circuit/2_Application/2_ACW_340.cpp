// Problem: https://www.acwing.com/problem/content/342/

// BFS最短路 + 二分，求“最大值最小”问题
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010, M = 20010;
int n, m, k;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
deque<int> q;  // 双端队列，边权为 0 存前面，边权为 1 存后面
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(int bound) {
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    q.push_back(1);
    dist[1] = 0;

    while (q.size()) {
        int now = q.front();
        q.pop_front();

        if (st[now])
            continue;

        st[now] = true;

        for (int i = h[now]; i != -1; i = ne[i]) {
            // 如果边权大于 bound，设为 1；小于等于 bound，设为 0
            int next = e[i], x = (w[i] > bound);
            if (dist[next] > dist[now] + x) {
                dist[next] = dist[now] + x;
                if (!x)
                    q.push_front(next);
                else
                    q.push_back(next);
            }
        }
    }

    return dist[n] <= k;
}

void solve() {
    cin >> n >> m >> k;

    // 建图
    memset(h, -1, sizeof h);
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    // 二分
    int l = 0, r = 1e6 + 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    // 输出结果
    if (r == 1e6 + 1)
        r = -1;
    cout << r << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}