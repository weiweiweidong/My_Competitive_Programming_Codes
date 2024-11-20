// Problem: https://www.acwing.com/problem/content/831/
// 数组模拟队列
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
// hh 表示队头，tt 表示队尾
int q[N], hh, tt;
int m;

// 队列初始化
void init() {
    hh = 0;
    tt = -1;
}

void solve() {
    // 初始化
    init();

    cin >> m;
    while (m--) {
        string op;
        int x;
        cin >> op;
        // 入队列
        if (op == "push") {
            cin >> x;
            tt++;
            q[tt] = x;
        }
        // 队头弹出
        else if (op == "pop")
            hh++;
        // 判断是否为空
        else if (op == "empty")
            cout << (hh <= tt ? "NO" : "YES") << endl;
        // 输出队头元素
        else
            cout << q[hh] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}