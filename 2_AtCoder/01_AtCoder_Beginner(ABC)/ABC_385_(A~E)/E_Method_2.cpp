// Problem: https://atcoder.jp/contests/abc385/tasks/abc385_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b;

void solve() {
    cin >> n;

    vector<vector<int>> tree(n);
    vector<int> deg(n, 0);

    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--, b--;

        tree[a].push_back(b);
        tree[b].push_back(a);

        deg[a]++;
        deg[b]++;
    }

    int res = n;
    // 遍历每个节点
    for (int v = 0; v < n; v++) {
        vector<int> d;
        // 获取和 v 相连的点的度数
        for (auto to : tree[v])
            d.push_back(deg[to]);
        // 按照度数降序排列
        sort(d.begin(), d.end(), greater<int>());

        for (int i = 1; i <= d.size(); i++) {
            int num = d[i - 1] * i + 1;
            res = min(res, n - num);
        }
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}