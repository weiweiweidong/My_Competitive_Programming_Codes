// Problem: https://www.acwing.com/problem/content/240/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e4 + 10;
int T;
int p[N];
int sz[N];  // 集合的大小
int d[N];   // x 到祖宗节点p[x]的距离

int find(int x) {
    // 路径压缩
    if (p[x] != x) {
        int root = find(p[x]);  // 找到祖宗节点
        d[x] += d[p[x]];        // 更新x到祖宗节点的距离
        p[x] = root;            // 更新x的祖宗节点
    }
    return p[x];  // 返回 x 的祖宗节点
}

void solve() {
    // 并查集初始化
    for (int i = 0; i < N; i++)
        p[i] = i, sz[i] = 1;

    cin >> T;
    while (T--) {
        char op;
        int a, b;
        cin >> op >> a >> b;
        // 合并（把 a 接到 b 后面）
        if (op == 'M') {
            int pa = find(a), pb = find(b);
            if (pa != pb) {
                d[pa] = sz[pb];    // pb 的尺寸就是 pa 到祖宗的距离
                sz[pb] += sz[pa];  // pa 集合的尺寸加入 pb 中
                p[pa] = pb;        // pb 成为 pa 的祖宗
            }
        }
        // 查询
        else {
            int pa = find(a), pb = find(b);
            // 不在一个组
            if (pa != pb)
                cout << -1 << endl;
            // 在一个组
            else
                cout << max(0, abs(d[a] - d[b]) - 1) << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}