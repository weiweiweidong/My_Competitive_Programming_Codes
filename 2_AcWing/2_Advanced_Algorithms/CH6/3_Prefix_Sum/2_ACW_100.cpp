// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int b[N], a[N];

void solve() {
    int n;
    cin >> n;
    // 读入数据，处理差分
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }

    LL pos = 0;  // b2～bn 的正数的和
    LL neg = 0;  // b2～bn 的负数总和
    // 贪心
    for (int i = 2; i <= n; i++) {
        if (b[i] > 0)
            pos += b[i];
        else
            neg -= b[i];
    }

    // 输出结果
    cout << min(pos, neg) + abs(pos - neg) << endl;
    cout << abs(pos - neg) + 1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}