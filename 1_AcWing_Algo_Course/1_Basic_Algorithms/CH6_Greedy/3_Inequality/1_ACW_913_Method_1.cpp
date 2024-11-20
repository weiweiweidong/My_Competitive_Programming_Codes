// Problem: https://www.acwing.com/problem/content/description/915/
// 前缀和写法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
LL a[N], s[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a, a + n + 1);

    LL res = 0;
    for (int i = 1; i < n; i++) {
        s[i] = 1LL * s[i - 1] + a[i];
        res += s[i];
    }
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}