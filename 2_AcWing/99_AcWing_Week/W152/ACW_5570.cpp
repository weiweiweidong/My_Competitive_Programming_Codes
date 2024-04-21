// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n;

// 方法1:暴力搜索
void solve() {
    cin >> n;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 6 == 0 || i % 8 == 0)
            res++;
    }

    cout << res << endl;
}

// 方法2:容斥原理
void solve2() {
    cin >> n;
    int res = n / 6 + n / 8 - n / 24;
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    // solve();
    solve2();
    return 0;
}