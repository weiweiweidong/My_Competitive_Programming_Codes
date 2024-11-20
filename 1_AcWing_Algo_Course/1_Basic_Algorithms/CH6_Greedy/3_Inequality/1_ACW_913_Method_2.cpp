// Problem: https://www.acwing.com/problem/content/description/915/
// 直接计算(用技巧)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
LL a[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a, a + n);
    reverse(a, a + n);

    LL res = 0;
    // 这里的递推公式非常的巧妙
    for (int i = 1; i < n; i++)
        res += a[i] * i;

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}