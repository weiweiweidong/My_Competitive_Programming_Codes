// Problem: https://www.acwing.com/problem/content/832/
// 使用单调栈，输出每个数左边第一个比它小的数
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int stk[N], tt;
int n;

void solve() {
    cin >> n;
    while (n--) {
        int x;
        cin >> x;
        while (tt && stk[tt] >= x)
            tt--;
        if (tt == 0)
            cout << "-1 ";
        else
            cout << stk[tt] << " ";
        tt++;
        stk[tt] = x;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}