// Problem: https://atcoder.jp/contests/abc397/tasks/abc397_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;
int num[N];  // 记录原始数组
// 记录，从“前往后看”和从“后往前看”，截止每个位置的不重复数字个数
int pre[N], suc[N];
unordered_set<int> s;
int n, x;

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> num[i];

    // 从前往后看
    for (int i = 1; i <= n; i++) {
        s.insert(num[i]);
        pre[i] = s.size();
    }
    // 清空 set
    s.clear();
    // 从后往前看
    for (int i = n; i >= 1; i--) {
        s.insert(num[i]);
        suc[i] = s.size();
    }

    // 开始求前后集合的最大值
    int res = 0;
    for (int i = 1; i <= n - 1; i++)
        res = max(res, pre[i] + suc[i + 1]);

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}