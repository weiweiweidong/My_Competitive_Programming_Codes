// Problem: https://www.acwing.com/problem/content/830/
// 数组模拟栈
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int m;
int stk[N], tt;

void solve() {
    cin >> m;
    while (m--) {
        string op;
        int x;
        cin >> op;

        // 栈顶推入元素
        if (op == "push") {
            cin >> x;
            tt++;
            stk[tt] = x;
        }
        // 栈顶弹出元素
        else if (op == "pop")
            tt--;
        // 判断栈是否为空
        else if (op == "empty")
            cout << (tt ? "NO" : "YES") << endl;
        // 输出栈顶元素
        else if (op == "query")
            cout << stk[tt] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}