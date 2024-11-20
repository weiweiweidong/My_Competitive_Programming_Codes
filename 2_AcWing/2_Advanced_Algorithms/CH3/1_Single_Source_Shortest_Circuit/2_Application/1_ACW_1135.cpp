// Problem: https://www.acwing.com/problem/content/1137/

// Dijkstra 与 DFS 联合使用
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e4 + 10, M = 2e5 + 10;
int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[6][N];
int st[N];

int point[6];
bool stv[6];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx;
    idx++;
}

// dijkstra 枚举 point 里面的点到各个点的最短路
void dijkstra() {
    memset(dist, 0x3f, sizeof dist);

    // 枚举起点
    for (int i = 0; i < 6; i++) {
        int start = point[i];
        dist[i][start] = 0;
        memset(st, 0, sizeof st);

        priority_queue<PII, vector<PII>, greater<PII>> heap;
        heap.push({0, start});

        while (heap.size()) {
            auto t = heap.top();
            heap.pop();
            int now = t.second, distance = t.first;
            if (st[now])
                continue;
            st[now] = true;

            for (int j = h[now]; j != -1; j = ne[j]) {
                int next = e[j];
                if (dist[i][next] > dist[i][now] + w[j]) {
                    dist[i][next] = dist[i][now] + w[j];
                    heap.push({dist[i][next], next});
                }
            }
        }
    }
}

// dfs 深搜，u 为要搜的点的下标
int dfs(int u) {
    // 标注 u 已经被占用
    stv[u] = true;

    int res = 0x3f3f3f3f;
    // 找下一个点
    for (int i = 0; i < 6; i++) {
        int len = 0;
        // 如果 i 点还没被用掉
        if (!stv[i]) {
            // 计算一下 u -> i 的最短距离
            len = dist[u][point[i]];
            // 获取 i 以后得最短距离
            len += dfs(i);
            res = min(res, len);
        }
    }

    stv[u] = false;  // 恢复现场
    if (res == 0x3f3f3f3f)  // 如果 res 没被更新，说明已经是最后一个点了
        return 0;
    return res;
}

void solve() {
    // 读入数据
    cin >> n >> m;
    for (int i = 1; i <= 5; i++)
        cin >> point[i];
    point[0] = 1;

    // 建图
    memset(h, -1, sizeof h);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    // 预处理
    dijkstra();

    // 找最短路径
    cout << dfs(0) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}