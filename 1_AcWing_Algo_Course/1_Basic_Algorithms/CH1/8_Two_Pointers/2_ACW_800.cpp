// Problem: https://www.acwing.com/problem/content/802/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int a[N], b[N];
int n, m, x;

void solve() {
    // 读入数据
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    // 双指针遍历
    for (int i = 0, j = m - 1; i < n; i++) {
        while (j >= 0 && a[i] + b[j] > x)
            j--;
        // 如果和为x，输出结果
        if (j >= 0 && a[i] + b[j] == x)
            cout << i << " " << j << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}