// Problem: https://atcoder.jp/contests/abc384/tasks/abc384_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int A[N];
LL sum[N];
LL n, s;
set<LL> h;

void solve() {
    // 读入数据，维护 前缀和 和 set
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> A[i];
        sum[i] = sum[i - 1] + A[i];
        h.insert(sum[i]);
    }

    s %= sum[n];
    sum[n + 1] = sum[n];
    bool can = false;

    // 从后往前逐个遍历
    for (int i = n + 1; i >= 1; i--) {
        // 计算出后缀和
        LL left = sum[n + 1] - sum[i - 1];
        // 计算出期待的前缀和
        LL right = s - left;
        // 看是否存在
        if (h.count(right))
            can = true;
        if (h.count(right + sum[n]))
            can = true;
        if (can)
            break;
    }
    if (can)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}