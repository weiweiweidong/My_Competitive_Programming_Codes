// Problem: https://atcoder.jp/contests/abc386/tasks/abc386_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;

LL res;
LL a[N];
int n, k;

void dfs(int x, LL sum, int n, int k) {
    // 搜到底了
    if (k == 0) {
        res = max(res, sum);
        return;
    }
    // 超出范围了
    if (x == n + 1)
        return;

    // 选中当前值
    dfs(x + 1, sum ^ a[x], n, k - 1);
    // 不选当前值
    dfs(x + 1, sum, n, k);
}

void solve() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    LL sum = 0;
    // 如果 k 比较大，C(k,n)比较难算，我们就算C(n-k,n)
    if (k > n / 2) {
        k = n - k;
        for (int i = 1; i <= n; i++)
            sum ^= a[i];
    }

    // dfs
    dfs(1, sum, n, k);

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}