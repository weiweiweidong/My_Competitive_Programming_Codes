#include <bits/stdc++.h>
using namespace std;
#define LL long long

LL n, d[200005], vis[200005];
vector<pair<LL, LL>> e[200005];

int main() {
    cin >> n;
    // 构建图e。e存储的是{点编号，边权中}
    for (LL i = 1; i <= n - 1; ++i) {
        LL a, b, x;
        cin >> a >> b >> x;
        e[i].push_back({i + 1, a});
        e[i].push_back({x, b});
    }

    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));

    // q 储存的是{权重，点编号}
    priority_queue<pair<LL, LL>> q;
    q.push({0, 1}), d[1] = 0;
    while (q.size()) {
        // 取出点编号
        LL u = q.top().second;
        q.pop();
        // 如果这个点已经被更新为最小值了，就跳过
        if (vis[u])
            continue;
        // 标记为已更新
        vis[u] = 1;
        // 对于u点下面的每条边
        for (auto p : e[u]) {
            // 取出点编号，边权重
            LL v = p.first, w = p.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                // priority_queue 默认是大根堆，这里需要小根堆，就存入了一个负值
                if (!vis[v])
                    q.push({-d[v], v});
            }
        }
    }
    cout << d[n] << endl;

    return 0;
}