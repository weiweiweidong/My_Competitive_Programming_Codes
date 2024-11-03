// Problem:

// 求图内的任意两个点间的最短路：floyd 算法

/*
技巧：
对于图论问题：“删边”和“删点”一般不好做，但是“加边”和“加点”会好做很多。
例如：删边后求连通性很难做，但每次加边求连通性（用并查集）就很好做。

思路：
1.所以可以考虑将操作“逆转”（从删完边后的图开始，慢慢加边），同时更新所有点间的距离
d[i][j]，此时查询两点间的距离就变成了O(1)的复杂度

2.将“加边后更新所有点之间的最短路”的复杂度降低即可，差不多 N^2=300^2=9e4

3.（官方题解做法）加入一条新边u--v，那么对于点x--y，若其最短路发生变化，新的最短路一定经过
u--v。那么新的最短路要么是 x--u--v--y，要么是 x--v--u--y，分类讨论即可：
dis[x][y]=min(dis[x][y] , dis[x][u]+c+dis[v][y] , dis[x][v]+c+dis[u][y])
时间复杂度：
1 类操作：O(N^2)
2 类操作：O(1)
总时间复杂度：300N^2 + QO(1) = 2.7e7+2e5 = 2.7e7
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAXN = 310;
const int MAXM = 50000;

// 存储所有的边
struct Edge {
    int u, v;
    LL c;
    bool is_del = false;
};
Edge edges[MAXM];

// 存储所有的查询
struct Query {
    int op, x, y;
    LL edge_weight;
    LL ans;
};
vector<Query> queries;

LL dist[MAXN][MAXN];
int n, m, q;

// floyd 计算任意两点间的最短路
void floyd(int k) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void solve() {
    // 存储所有的边
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++) {
        int u, v;
        LL c;
        cin >> u >> v >> c;
        edges[i] = {u, v, c};
    }

    // 存储所有的操作
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        // 操作 1：删除边
        if (op == 1) {
            // 根据边的编号，找到边的 u v c，并存入 queries 中
            int edge_id;
            cin >> edge_id;
            edges[edge_id].is_del = true;
            auto [u, v, c, _] = edges[edge_id];
            queries.push_back({1, u, v, c, 0});
        }
        // 操作 2：查询
        else {
            int x, y;
            cin >> x >> y;
            queries.push_back({2, x, y, 0, 0});
        }
    }

    // dist 初始化
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    // 使用边来更新 dist 矩阵（本质是邻接矩阵）
    for (int i = 1; i <= m; i++) {
        auto [u, v, c, is_del] = edges[i];
        if (is_del)
            continue;
        dist[u][v] = min(dist[u][v], c);
        dist[v][u] = min(dist[v][u], c);
    }
    // floyd 求任意两点间的最短距离
    for (int i = 1; i <= n; i++)
        floyd(i);

    // 从后往前处理 query
    reverse(queries.begin(), queries.end());
    for (auto& query : queries) {
        auto [op, u, v, c, ans] = query;
        // 如果是删除边操作，就把边加回来，更新 dist 矩阵
        if (op == 1) {
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dist[i][j] = min({dist[i][j], dist[i][u] + c + dist[v][j],
                                      dist[i][v] + c + dist[u][j]});
        }
        // 如果是查询操作，直接读取距离
        else {
            query.ans = dist[u][v];
        }
    }

    // 把所有操作调转回来
    reverse(queries.begin(), queries.end());
    for (auto& query : queries) {
        // 如果是查询操作，直接输出答案
        if (query.op == 2)
            cout << (query.ans == 0x3f3f3f3f3f3f3f3f ? -1 : query.ans) << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}