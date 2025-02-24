// Problem: https://atcoder.jp/contests/abc393/tasks/abc393_f

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int INF = 1e9 + 10;

void solve() {
    int n, q;
    cin >> n >> q;

    // 读入原数组数据
    vector<int> a(n);
    for (int& i : a)
        cin >> i;

    // 存储所有的查询
    vector<vector<PII>> qs(n);
    for (int i = 0; i < q; i++) {
        int r, x;
        cin >> r >> x;
        qs[--r].emplace_back(i, x);
    }

    vector<int> res(q);
    vector<int> dp(n, INF);

    for (int i = 0; i < n; i++) {
        // 找到dp数组中第一个大于等于a[i]的位置
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        *it = a[i];  // 更新该位置的值为a[i]

        // 处理所有询问位置为 i 的查询
        for (auto [id, x] : qs[i])
            // 计算dp数组中第一个大于x的位置，即为答案
            res[id] = upper_bound(dp.begin(), dp.end(), x) - dp.begin();
    }

    for (int i = 0; i < q; i++)
        cout << res[i] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}