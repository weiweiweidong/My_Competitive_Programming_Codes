// Problem: https://www.acwing.com/problem/content/897/
// 最长上升子序列：暴力写法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
int n;
int a[N], f[N];

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // f数组初始化
    for (int i = 1; i <= n; i++)
        f[i] = 1;

    // 状态转移
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (a[i] > a[j])
                f[i] = max(f[i], f[j] + 1);
        }
    }

    // 遍历最大值
    int res = 0;
    for (int i = 0; i <= n; i++)
        res = max(res, f[i]);
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}