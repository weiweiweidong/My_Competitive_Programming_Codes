// Problem: https://atcoder.jp/contests/abc380/tasks/abc380_e

// 使用并查集处理区间染色问题
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e6 + 10;

// 节点的父节点，每个集合的节点数，集合的最左端点，集合的最右端点
int fa[N], cnt[N], l[N], r[N];
int color[N];      // 节点 i 的颜色
int color_cnt[N];  // 颜色 i 的数量
int n, q;

// 查找节点 x 所属的集合
int _find(int x) {
    // 如果 x 是根节点，就返回 x
    // 如果不是，就继续找祖宗。同时进行路径压缩
    return x == fa[x] ? x : fa[x] = _find(fa[x]);
}

// 将 x 所在集合涂成颜色 c
void paint(int x, int c) {
    x = _find(x);                   // 找 x 的祖宗
    color_cnt[color[x]] -= cnt[x];  // 从原来的颜色计数中减去整个集合的大小
    color[x] = c;                   // 染色
    color_cnt[c] += cnt[x];  // 新颜色计数中添加整个集合大小
}

// 合并两个集合
void _union(int x, int y) {
    int fx = _find(x), fy = _find(y);  // 找到两个节点的祖宗节点
    fa[fx] = fy;                       // fx 的祖宗改为 fy
    l[fy] = min(l[fx], l[fy]);         // 更新合并后集合的左边界
    r[fy] = max(r[fx], r[fy]);         // 更新合并后集合的右边界
    cnt[fy] += cnt[fx];                // 更新合并后集合的节点数量
}

void solve() {
    // 读入数据
    cin >> n >> q;
    // 将每个节点
    for (int i = 1; i <= n; i++) {
        // 初始化：每个节点的颜色，父节点，左边界，右边界
        color[i] = fa[i] = l[i] = r[i] = i;
        cnt[i] = 1;  // 初始化：每个集合计数，只有一个节点
        color_cnt[i] = 1;  // 初始化：每种颜色只有一个节点
    }

    while (q--) {
        int op;
        cin >> op;
        // 操作 1：染色操作
        if (op == 1) {
            int x, c;
            cin >> x >> c;  // 读入要染色的节点和 x 和目标颜色 c
            paint(x, c);    // 染色

            // 检查并合并相邻的同色集合
            int L = l[_find(x)], R = r[_find(x)];
            // 如果左边相邻集合同色
            if (color[_find(L - 1)] == c)
                _union(L - 1, x);
            // 如果右边相邻集合同色
            if (color[_find(R + 1)] == c)
                _union(R + 1, x);
        }
        // 操作 2：查询操作
        else {
            int c;
            cin >> c;
            cout << color_cnt[c] << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}