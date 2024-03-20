// Problem: https://atcoder.jp/contests/abc302/tasks/abc302_e
// STL的使用
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;
int n, q;
int op, u, v;
unordered_map<int, unordered_set<int>> graph;  // 邻接表存储图
int degree[N];                                 // 存储每个节点的度数
unordered_set<int> points;                     // 存储落单的点

void solve() {
    // n个点，q次查询
    cin >> n >> q;
    // 存储所有的落单点
    for (int i = 1; i <= n; i++)
        points.insert(i);

    while (q--) {
        cin >> op;
        // 操作1:添加边
        if (op == 1) {
            // 插入两条边
            cin >> u >> v;
            graph[u].insert(v), graph[v].insert(u);  // 更新邻接表
            degree[u]++, degree[v]++;                // 更新度数

            // 更新落单点
            if (points.find(u) != points.end())
                points.erase(points.find(u));
            if (points.find(v) != points.end())
                points.erase(points.find(v));
            // 输出
            cout << points.size() << endl;
        }
        // 操作2:删除边
        else if (op == 2) {
            cin >> v;
            // 遍历v的每一个临点
            for (auto it = graph[v].begin(); it != graph[v].end(); it++) {
                u = *it;
                graph[u].erase(graph[u].find(v));
                degree[u]--;
                if (degree[u] == 0)
                    points.insert(u);
            }
            degree[v] = 0;
            graph[v].clear();
            points.insert(v);

            cout << points.size() << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}