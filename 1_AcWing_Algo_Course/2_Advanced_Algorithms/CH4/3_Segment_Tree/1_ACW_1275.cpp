// Problem:https://www.acwing.com/problem/content/1277/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 200010;

int m, p;
struct Node {
    int l, r;
    int v;  // 区间[l, r]中的最大值
} tr[N * 4];

// 根据子节点，计算父节点（u是父节点的index）
void pushup(int u) {
    // 父节点的最大值 = 两个自节点的最大值
    tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

// 从上往下构建
// （u是线段树数组的index；此时没有赋值v，只是预先开辟了所有的线段树数组位置）
void build(int u, int l, int r) {
    // 初始化左右区间
    tr[u] = {l, r};
    // 如果是叶节点，就直接返回
    if (l == r)
        return;
    // 否则就更新左右子节点
    int mid = (l + r) >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

// 查询（u是线段树数组的index，l和r是想查的区间）
int query(int u, int l, int r) {
    // 树中节点，已经被完全包含在[l, r]中了
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].v;
    // 获取区间中点
    int mid = (tr[u].l + tr[u].r) >> 1;
    int v = 0;
    // 判断和左边的交集
    if (l <= mid)
        v = query(u << 1, l, r);
    // 判断和右边的交集
    if (r > mid)
        v = max(v, query(u << 1 | 1, l, r));

    return v;
}
// 修改操作
// u：线段树数组的index
// x：原数组的index
// v：变更后的值
void modify(int u, int x, int v) {
    // 如果已经是叶节点，就直接修改值
    if (tr[u].l == x && tr[u].r == x)
        tr[u].v = v;
    else {
        // 取中点
        int mid = (tr[u].l + tr[u].r) >> 1;
        // 找左边
        if (x <= mid)
            modify(u << 1, x, v);
        // 找右边
        else
            modify(u << 1 | 1, x, v);
        // 更新当前节点的信息（上面已经把子节点信息全更新完了）
        pushup(u);
    }
}

int main() {
    // n表示数组长度，last表示上一个query操作的结果
    int n = 0, last = 0;
    scanf("%d%d", &m, &p);
    // 初始化线段树（从头开始构建）
    // 线段树index起点为1，范围为[1,m]
    build(1, 1, m);

    int x;
    char op[2];
    while (m--) {
        scanf("%s%d", op, &x);
        // 查询操作（查询最后x个数的最大值）
        if (*op == 'Q') {
            // 从上往下找，最后x个数所在区间为[n-x+1,n]
            last = query(1, n - x + 1, n);
            printf("%d\n", last);
        }
        // 插入操作（把n+1位置修改为 (x+last)%p 值）
        else {
            modify(1, n + 1, (x + (LL)last) % p);
            n++;
        }
    }

    return 0;
}