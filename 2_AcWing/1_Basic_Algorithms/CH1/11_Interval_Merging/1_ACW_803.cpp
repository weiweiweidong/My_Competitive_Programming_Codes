// Problem: https://www.acwing.com/problem/content/805/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n;

void interval_merge(vector<PII>& segs) {
    vector<PII> res;
    // 排序。默认是按照 pair 的 first 升序排列
    sort(segs.begin(), segs.end());

    // 设置初始 st 和 ed，是一个无穷小的数
    int st = -2e9, ed = -2e9;
    // 开始遍历每一个小区间
    for (auto seg : segs) {
        // ed < seg.first 意味着 上一个区间和新的区间没有重叠
        if (ed < seg.first) {
            // 保存上一个区间
            if (st != -2e9)
                res.push_back({st, ed});
            // 把新区间更新到 st和ed 上
            st = seg.first, ed = seg.second;
        }
        // 有重叠，就更新ed的值
        else {
            ed = max(ed, seg.second);
        }
    }
    if (st != -2e9)
        res.push_back({st, ed});
    segs = res;
}

void solve() {
    cin >> n;
    // 读入所有的区间
    vector<PII> segs;
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        segs.push_back({l, r});
    }

    interval_merge(segs);

    cout << segs.size() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}