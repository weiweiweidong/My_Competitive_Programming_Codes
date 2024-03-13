// Problem: https://www.acwing.com/problem/content/828/
// 用数组实现单链表
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
// head 表示头结点的下标
// e[i] 表示节点i的值
// ne[i] 表示节点i指向哪个节点
// idx 存储当前已经用到了哪个点
int head, e[N], ne[N], idx;
int m;

// 初始化
void init() {
    head = -1;
    idx = 0;
}
// 将x插到头结点
void add_to_head(int x) {
    e[idx] = x;
    ne[idx] = head;
    head = idx;
    idx++;
}
// 将x插到idx是k的点后面
void add(int k, int x) {
    e[idx] = x;
    ne[idx] = ne[k];
    ne[k] = idx;
    idx++;
}
// 将idx是k的点后面的点删掉
void remove(int k) {
    ne[k] = ne[ne[k]];
}

void solve() {
    // 重要：初始化
    init();

    cin >> m;
    while (m--) {
        int x, k;
        char op;
        cin >> op;
        // 插在头部
        if (op == 'H') {
            cin >> x;
            add_to_head(x);
        }
        // 删除节点
        else if (op == 'D') {
            cin >> k;
            if (k == 0)
                head = ne[head];
            else
                remove(k - 1);
        }
        // 在第k节点后面添加x节点
        else {
            cin >> k >> x;
            add(k - 1, x);
        }
    }

    for (int i = head; i != -1; i = ne[i])
        cout << e[i] << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}