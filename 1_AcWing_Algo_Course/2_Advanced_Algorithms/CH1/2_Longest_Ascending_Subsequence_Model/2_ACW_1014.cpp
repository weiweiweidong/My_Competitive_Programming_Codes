// Problem: https://www.acwing.com/problem/content/1016/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int N = 1010;
int n;
int h[N], f[N], g[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    // 从前往后的最长上升子序列
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++) {
            if (h[i] > h[j])
                f[i] = max(f[i], f[j] + 1);
        }
    }

    // 从后往前的最长上升子序列
    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        for (int j = n; j > i; j--) {
            if (h[i] > h[j])
                g[i] = max(g[i], g[j] + 1);
        }
    }

    // 遍历一遍，求出结果
    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, f[i] + g[i] - 1);

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}