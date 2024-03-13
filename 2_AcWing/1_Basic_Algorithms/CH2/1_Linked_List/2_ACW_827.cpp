// Problem: https://www.acwing.com/problem/content/829/
// 数组实现双链表
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int e[N], l[N], r[N], idx;
int m;

// 双链表初始化
void init() {
    // 0 表示左端点，1 表示右端点
    r[0] = 1, l[1] = 0;
    idx = 2;
}
// 在 k 右边插入 x
// 同理，在 k 的左边插入 x ，也可以等价于调用下面函数 insert(l[k] , x)
// l[k] 指向了 k 左边的节点
void insert(int k, int x) {
    e[idx] = x;

    r[idx] = r[k];
    l[idx] = k;
    l[r[k]] = idx;
    r[k] = idx;

    idx++;
}
// 删除k节点
void remove(int k) {
    l[r[k]] = l[k];
    r[l[k]] = r[k];
}

void solve() {
    init();
    cin >> m;
    while (m--) {
        string op;
        int x, k;
        cin >> op;
        if (op == "L") {
            cin >> x;
            // 最左端插入 x ，等价于 在 0 端点右侧插入 x
            insert(0, x);
        } else if (op == "R") {
            cin >> x;
            // 最右端插入 x ，等价于 在 1 端点左侧插入 x
            insert(l[1], x);
        } else if (op == "D") {
            cin >> k;
            // 因为在双链表中，idx 被初始化为 2， 所以这里第 k 个数是
            // k+1；在单链表里 idx 初始化为0， 所以第k个数为 k-1
            remove(k + 1);
        } else if (op == "IL") {
            cin >> k >> x;
            insert(l[k + 1], x);
        } else {
            cin >> k >> x;
            insert(k + 1, x);
        }
    }

    for (int i = r[0]; i != 1; i = r[i])
        cout << e[i] << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}