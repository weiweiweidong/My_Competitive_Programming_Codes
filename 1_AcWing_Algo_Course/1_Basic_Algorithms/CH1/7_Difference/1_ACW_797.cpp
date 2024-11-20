// Problem: https://www.acwing.com/problem/content/799/
// 一维差分
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int a[N], b[N];
int n, m;

void solve() {
    cin >> n >> m;
    // 读入原数组，并预处理差分
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
    }
    // 进行m次操作
    while (m--) {
        int l, r, c;
        cin >> l >> r >> c;
        b[l] += c, b[r + 1] -= c;
    }
    // 更新a数组，并输出
    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + b[i];
        cout << a[i] << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}