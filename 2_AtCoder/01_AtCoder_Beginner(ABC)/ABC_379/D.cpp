// Problem: https://atcoder.jp/contests/abc379/tasks/abc379_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int q;
int op;
LL x;

void solve() {
    cin >> q;

    queue<LL> Q;  // 队列
    LL now = 0;   // 记录当前时间

    while (q--) {
        cin >> op;
        // 种植物
        if (op == 1) {
            Q.push(now);
        }
        // 等待 x 天
        else if (op == 2) {
            cin >> x;
            now += x;
        }
        // 收割高于 x 的植物
        else {
            cin >> x;
            int res = 0;
            while (Q.size() && now - Q.front() >= x) {
                res++;
                Q.pop();
            }
            cout << res << endl;
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}