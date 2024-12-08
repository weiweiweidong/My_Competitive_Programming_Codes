// Problem: https://atcoder.jp/contests/abc383/tasks/abc383_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10, M = 20 * N;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];
int st[N];

int H, W, d;
char g[1010][1010];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
}

// SPFA 算法
void spfa() {
    int start = 1e6 + 5;
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
    // 读入网格数据
    cin >> H >> W >> d;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            cin >> g[i][j];

    // 建图
    memset(h, -1, sizeof h);
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++) {
            // ‘#’点不建图
            if (g[i][j] == '#')
                continue;
            int now = i * W + j;
            // ‘H’点额外添加和虚拟节点 1e6+5 的 0 边权的边
            if (g[i][j] == 'H') {
                add(1e6 + 5, now, 0), add(now, 1e6 + 5, 0);
            }
            // 看一下周围四个点能不能建边
            for (int k = 0; k < 4; k++) {
                int a = i + dx[k], b = j + dy[k];
                // 越界
                if (a < 0 || a >= H || b < 0 || b >= W)
                    continue;
                // 遇到 #
                if (g[a][b] == '#')
                    continue;
                // 建边
                add(now, a * W + b, 1);
            }
        }

    spfa();

    // 遍历，看距离 H 在 d 以内的点有多少
    int res = 0;
    for (int i = 0; i < H; i++)
        for (int j = 0; j < W; j++)
            if (g[i][j] != '#' && dist[i * W + j] <= d)
                res++;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}