// Problem: https://www.acwing.com/problem/content/907/
// 贪心：区间问题（struct 内重载小于号）
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
struct Range {
    int l, r;
    bool operator<(const Range& W) const { return r < W.r; }
} range[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }
    // 此时是按照区间的右端点排序
    sort(range, range + n);

    int res = 0, ed = -2e9;
    for (int i = 0; i < n; i++) {
        // 只要新区间的l 超过了last区间的r，说明不相交
        if (range[i].l > ed) {
            res++;
            ed = range[i].r;
        }
    }

    // 也就是说找到了cnt个两两不相交的区间
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}