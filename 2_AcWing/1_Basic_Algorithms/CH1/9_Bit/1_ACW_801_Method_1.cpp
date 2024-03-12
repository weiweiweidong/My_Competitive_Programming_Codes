// Problem: https://www.acwing.com/problem/content/803/
// 逐步位运算，计算二进制中有多少个1
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int a[N];
int n;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int x = a[i];
        int res = 0;
        // 逐步位运算
        while (x) {
            // 获取最后一位
            res += x & 1;
            // 右移一位
            x >>= 1;
        }
        cout << res << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}