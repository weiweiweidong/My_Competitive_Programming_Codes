// Problem: https://atcoder.jp/contests/abc376/tasks/abc376_a

// 模拟题
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, c;
int res;
int last;
int t;

void solve() {
    cin >> n >> c;
    last = -c;  // 记录上次拿糖的时间，初始值设一个比较小的数即可
    for (int i = 1; i <= n; i++) {
        cin >> t;           // 读入当前时间
        if (t - last >= c)  // 间隔时间超过 c，就可以拿糖
            res++, last = t;
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}