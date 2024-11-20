// Problem: https://www.acwing.com/problem/content/1014/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 5010;
int n;
PII q[N];
int f[N];

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> q[i].first >> q[i].second;
    // 对数组排序：PII对的第一个数排序
    sort(q, q + n);

    int res = 0;
    // DP：找最长上升子序列
    for (int i = 0; i < n; i++) {
        f[i] = 1;
        for (int j = 0; j < i; j++) {
            if (q[i].second > q[j].second)
                f[i] = max(f[i], f[j] + 1);
        }
        res = max(res, f[i]);
    }

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}