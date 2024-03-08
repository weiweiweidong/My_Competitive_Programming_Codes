// Problem: https://www.acwing.com/problem/content/246/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;
int n, m;
int w[N];  // 储存序列里的每一个数
struct Node {
    int l, r;
    int sum, lmax, rmax, tmax;
} tr[4 * N];

// 通过左右子节点更新节点
void pushup(Node& u, Node& l, Node& r) {
    // 区间内的总和
    u.sum = l.sum + r.sum;
    // 最大前缀
    u.lmax = max(l.lmax, l.sum + r.lmax);
    // 最大后缀
    u.rmax = max(r.rmax, r.sum + l.rmax);
    // 最大子段和
    // （3种情况：没有跨区间的左最大和右最大，跨区间的最大）
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
}
void pushup(int u) {
    pushup(tr[u], tr[u * 2], tr[u * 2 + 1]);
}
// 从上向下构建线段树
void build(int u, int l, int r) {
    // 如果是叶节点
    if (l == r)
        tr[u] = {l, r, w[r], w[r], w[r], w[r]};
    // 如果是区间，就构建子段
    else {
        tr[u] = {l, r};
        int mid = (l + r) >> 1;
        build(u * 2, l, mid), build(u * 2 + 1, mid + 1, r);
        // 创建完成子段后，更新一下当前的u节点
        pushup(u);
    }
}
// 修改：把x位置改成v
void modify(int u, int x, int v) {
    // 如果是叶节点，直接改值
    if (tr[u].l == x && tr[u].r == x)
        tr[u] = {x, x, v, v, v, v};
    // 如果是区间，就向下继续找
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        if (x <= mid)
            modify(u * 2, x, v);
        else
            modify(u * 2 + 1, x, v);
        // 改完子段后，更新一下当前的u节点
        pushup(u);
    }
}
// 查询[l,r]区间的值，直接返回节点
Node query(int u, int l, int r) {
    // 如果是叶节点，直接返回叶节点
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    // 否则向下找
    else {
        int mid = (tr[u].l + tr[u].r) >> 1;
        // 要查询区间完全在左边
        if (r <= mid)
            return query(u * 2, l, r);
        // 要查询节点完全在右边
        else if (l > mid)
            return query(u * 2 + 1, l, r);
        // 交叉的情况下
        else {
            // 找到左边和右边
            auto left = query(u * 2, l, r);
            auto right = query(u * 2 + 1, l, r);
            // 最终结果
            Node res;
            pushup(res, left, right);
            return res;
        }
    }
}

int main() {
    // 读入数据
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    // 线段树初始化
    build(1, 1, n);

    int k, x, y;
    while (m--) {
        cin >> k >> x >> y;
        // 查询操作
        if (k == 1) {
            if (x > y)
                swap(x, y);
            cout << query(1, x, y).tmax << endl;
        }
        // 修改操作
        else
            modify(1, x, y);
    }
    return 0;
}
