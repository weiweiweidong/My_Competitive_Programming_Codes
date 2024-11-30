// Problem: https://www.acwing.com/problem/content/246/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;
int n, m;
int a[N];  // 原始数组，存储输入的数字

struct Node {
    int l, r;  // 该节点表示的区间范围[l,r]
    int sum;   // 区间总和
    int lmax;  // 包含左端点的最大子段和
    int rmax;  // 包含右端点的最大子段和
    int tmax;  // 区间内的最大子段和
} tr[4 * N];   // 开4倍空间确保足够

// 合并左右子节点信息，更新当前 u 节点
void pushup(Node& u, Node& l, Node& r) {
    // 区间和等于左子区间和加右子区间和
    u.sum = l.sum + r.sum;
    // 左端点的最大子段和
    u.lmax = max(l.lmax, l.sum + r.lmax);
    // 右端点的最大子段和
    u.rmax = max(r.rmax, r.sum + l.rmax);
    /*
    区间最大字段和可能是：
    1. 右子区间的最大子段和
    2. 右子区间的最大子段和
    3. 左子区间最大后缀和 加上 右子区间最大前缀和
    */
    u.tmax = max({l.tmax, r.tmax, l.rmax + r.lmax});
}

// pushup 函数重载
void pushup(int u) {
    pushup(tr[u], tr[u * 2], tr[u * 2 + 1]);
}

// 构建线段树
void build(int u, int l, int r) {
    // 叶节点
    if (l == r)
        tr[u] = {l, r, a[r], a[r], a[r], a[r]};
    else {
        tr[u] = {l, r};
        int mid = (l + r) / 2;
        // 递归构建左右子树
        build(u * 2, l, mid), build(u * 2 + 1, mid + 1, r);
        // 根据左右节点更新当前节点
        pushup(u);
    }
}

// 单点修改操作
void modify(int u, int x, int v) {
    // 叶节点：直接修改值
    if (tr[u].l == x && tr[u].r == x)
        tr[u] = {x, x, v, v, v, v};
    else {
        // 计算中点位置
        int mid = (tr[u].l + tr[u].r) / 2;
        // 根据位置决定递归左子树还是右子树
        if (x <= mid)
            modify(u * 2, x, v);
        else
            modify(u * 2 + 1, x, v);
        // 根据子树更新当前节点信息
        pushup(u);
    }
}

Node query(int u, int l, int r) {
    // 当前节点完全包含在查询区间内
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    else {
        int mid = (tr[u].l + tr[u].r) / 2;
        // 查询区间在左子树
        if (r <= mid)
            return query(u * 2, l, r);
        // 查询区间在右子树
        else if (l > mid)
            return query(u * 2 + 1, l, r);
        // 查询区间跨越左右子树
        else {
            auto left = query(u * 2, l, r);
            auto right = query(u * 2 + 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

void solve() {
    // 读入数组长度 和 操作次数
    cin >> n >> m;
    // 读入原始数组
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    // 线段树初始化
    build(1, 1, n);

    int k, x, y;
    // 处理 m 个操作
    while (m--) {
        cin >> k >> x >> y;
        // 查询操作
        if (k == 1) {
            if (x > y)
                swap(x, y);
            cout << query(1, x, y).tmax << endl;
        }
        // 单点修改操作
        else
            modify(1, x, y);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}