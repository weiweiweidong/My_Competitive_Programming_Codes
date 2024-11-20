// Problem: https://www.acwing.com/problem/content/909/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n, st, ed;
struct Range {
    int l, r;
} ranges[N];

bool cmp(Range a, Range b) {
    return a.l < b.l;
}

void solve() {
    cin >> st >> ed >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r};
    }

    sort(ranges, ranges + n, cmp);

    bool success = false;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        // 初始化这一段的 max_r
        int j = i;
        int max_r = -2e9;
        // 如果范围的左端点 小于等于 st
        while (j < n && ranges[j].l <= st) {
            // 更新一下max_r
            max_r = max(max_r, ranges[j].r);
            j++;
        }
        // 若max_r 小于 st，说明没有区间能覆盖掉 st
        if (max_r < st) {
            cnt = -1;
            break;
        }

        cnt++;
        // 如果 max_r 大于等于 ed 了，说明最后一个也找完了
        if (max_r >= ed) {
            success = true;
            break;
        }
        // 更新一下 st
        st = max_r;
        i = j - 1;
    }

    if (!success)
        cnt = -1;
    cout << cnt << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}