// Problem: https://www.acwing.com/problem/content/1277/

// 线段树 Segment Tree
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int m, p;
// 线段树节点
struct Node {
    int l, r;  // 存储节点的左右区间
    int v;     // // 区间[l, r]中的最大值
} tr[N * 4];   // 开 4 倍 N 大小

// 根据子节点，更新树状数组 u 节点的存储值 v
void pushup(int u) {
    // 左右两子树的最大值
    tr[u].v = max(tr[u * 2].v, tr[u * 2 + 1].v);
}

// 构建线段树（只记录左右区间，没有记录存储值 v）
void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r)
        return;
    int mid = (l + r) / 2;
    build(u * 2, l, mid), build(u * 2 + 1, mid + 1, r);
}

// 查询（u是线段树数组的index，l和r是想查的区间）
int query(int u, int l, int r) {
    // 判断节点区间是否完全包含在查询区间内
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].v;
    // 如果不完全包含，就需要分割查询
    int mid = (tr[u].l + tr[u].r) / 2;
    int v = 0;
    // 如果左边界在左子树区间内
    if (l <= mid)
        v = query(u * 2, l, r);
    // 如果右边界在右子树区间内
    if (r > mid)
        v = max(v, query(u * 2 + 1, l, r));

    return v;
}

// 修改操作
// u：线段树数组的index
// x：原数组的index（想要修改的位置）
// v：变更后的值
void modify(int u, int x, int v) {
    // 如果已经到叶节点了
    if (tr[u].l == x && tr[u].r == x)
        tr[u].v = v;
    else {
        // 线段树节点记录的区间中点
        int mid = (tr[u].l + tr[u].r) / 2;
        // 如果在节点的左子树：沿着左子树向下更新
        if (x <= mid)
            modify(u * 2, x, v);
        // 如果在节点的右子树：沿着右子树向下更新
        else
            modify(u * 2 + 1, x, v);
        // 因为左或右子树的值被更新了，所以要更新u处的值
        pushup(u);
    }
}

void solve() {
    // n 表示数组长度（即总区间的右端点），last 表示上个 query 操作的结果
    int n = 0, last = 0;
    cin >> m >> p;
    // 初始化线段树。
    // 线段数index 起点为 1，区间为[1,m]
    // 总共有m个操作，最极端情况下是往线段树中插入m个数，所以取[1,m]可以覆盖所有
    build(1, 1, m);

    int x;
    char op;
    while (m--) {
        cin >> op >> x;
        // 查询操作
        if (op == 'Q') {
            // 查询最后x个数中最大的数是多少
            last = query(1, n - x + 1, n);
            cout << last << endl;
        } else {
            // 在最后一个位置插入值
            modify(1, n + 1, (x + (LL)last) % p);
            n++;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}