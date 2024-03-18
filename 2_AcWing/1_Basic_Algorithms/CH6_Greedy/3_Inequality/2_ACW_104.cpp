// Problem: https://www.acwing.com/problem/content/106/
// 绝对值不等式
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

    sort(a, a + n);
    int res = 0;
    for (int i = 0, j = n - 1; i <= j; i++, j--)
        res += abs(a[i] - a[j]);
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}