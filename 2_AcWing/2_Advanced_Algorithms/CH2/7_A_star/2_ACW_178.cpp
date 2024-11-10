// Problem: https://www.acwing.com/problem/content/180/

// 看不懂，暂时先跳过
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;

#define x first
#define y second

const int N = 1010, M = 200010;

int n, m, S, T, K;
int h[N], rh[N], e[M], w[M], ne[M], idx;
int dist[N], cnt[N];
bool st[N];

// 在邻接表中添加边
void add(int h[], int a, int b, int c) {
    e[idx] = b;      // 编号idx的边指向 b 节点
    w[idx] = c;      // 编号idx的边边长为 c
    ne[idx] = h[a];  // 下一条边
    h[a] = idx++;  // 从 a 节点出去的各条边（链表）的第一条边
}

// 利用反向图，求出终点 T 到所有点的最短距离
// （就是估价函数的值）
void dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII>> heap;  // 小根堆
    heap.push({0, T});                                    // 终点

    memset(dist, 0x3f, sizeof dist);
    dist[T] = 0;

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int ver = t.y;
        if (st[ver])
            continue;
        st[ver] = true;

        for (int i = rh[ver]; ~i; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]) {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int astar() {
    // heap 存的三个值：
    // 1. 起点 S 到终点 T 的拘留。
    // 2. 点 ver 到起点 S 的距离。
    // 3. 点 ver 编号
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    heap.push({dist[S], {0, S}});

    while (heap.size()) {
        // 取出 heap 中，目前到终点 T 最近的点
        auto t = heap.top();
        heap.pop();

        // ver 是节点编号，distance 是从起点到 ver 的距离
        int ver = t.y.y, distance = t.y.x;
        // ver 出现次数++
        cnt[ver]++;
        // 如果终点出现次数为 K，说明找到了第 K 小的路径
        if (cnt[T] == K)
            return distance;

        // ver 的所有临边
        for (int i = h[ver]; ~i; i = ne[i]) {
            int next = e[i];
            // 如果下个点 next 出现次数小于 K
            if (cnt[next] < K)
                /*
                heap 存的三个值：
                1. 点ver到起点S的距离 + ver到next的边长 + next到终点最短距离。
                2. 点ver到next点的距离。
                3. 点next编号
                */
                heap.push(
                    {distance + w[i] + dist[next], {distance + w[i], next}});
        }
    }

    return -1;
}

void solve() {
    // 读入点和边的数量
    cin >> n >> m;
    // 初始化正向边
    memset(h, -1, sizeof h);
    // 初始化反向边
    memset(rh, -1, sizeof rh);
    // 读入各条边
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        add(h, a, b, c);  // 添加正向边
        add(rh, b, a, c);  // 添加反向边（用于求终点到各点的最短路径）
    }
    cin >> S >> T >> K;  // 起点，终点，求第 k短路

    // 如果起点终点相同的时候，需要特判一下
    if (S == T)
        K++;

    dijkstra();
    cout << astar() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}