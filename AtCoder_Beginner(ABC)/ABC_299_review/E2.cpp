#include <bits/stdc++.h>
#define GO       \
    cin.tie(0);  \
    cout.tie(0); \
    ios::sync_with_stdio(0);
typedef long long ll;
using namespace std;
const int N = 2e3 + 5;
// 邻接表存储图。表示声明了一个N大小的数组，每个数组中的元素是 vector<int>
vector<int> adj[N];
int dis[N][N];

void BFS(int s) {
    queue<int> q;
    q.push(s);
    dis[s][s] = 0;
    while (q.size()) {
        // 取出当前点
        int u = q.front();
        q.pop();
        // 遍历当前点的每一个临点
        for (int v : adj[u]) {
            // 如果数据已经被更新过了，就跳掉
            if (dis[s][v] != -1)
                continue;
            // 更新距离
            dis[s][v] = dis[s][u] + 1;
            q.push(v);
        }
    }
}

int main() {
    // 初始化dist，表示点与点之间距离未知
    GO memset(dis, -1, sizeof dis);
    int n, m;
    cin >> n >> m;

    // 读入图
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    // 对每个点做一次BFS
    for (int i = 1; i <= n; i++)
        BFS(i);

    // 读入数据
    int k;
    cin >> k;
    vector<pair<int, int> > v;
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    int d[n + 1];
    for (int i = 1; i <= n; i++)
        d[i] = 2e9;
    string ans = string(n, '0');
    // 遍历每个点
    for (int i = 1; i <= n; i++) {
        bool ok = 1;
        // 遍历每一个条件
        for (auto it : v) {
            // 如果 目标节点到i节点距离 小于 要求条件
            if (dis[it.first][i] < it.second)
                ok = 0;
        }
        if (ok) {
            for (auto it : v) {
                d[it.first] = min(d[it.first], dis[it.first][i]);
            }
            ans[i - 1] = '1';
        }
    }
    bool ok = 1;
    for (auto it : v) {
        if (d[it.first] != it.second)
            ok = 0;
    }
    if (!ok)
        cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        cout << ans << endl;
    }
    return 0;
}
