// Problem: https://www.acwing.com/problem/content/910/
// 最大不相交区间数量

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
struct Range {
    int l, r;
} range[N];

bool cmp(Range a, Range b) {
    return a.r < b.r;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        range[i] = {l, r};
    }

    sort(range, range + n, cmp);

    int cnt = 0, ed = -2e9;
    for (int i = 0; i < n; i++) {
        if (range[i].l > ed) {
            cnt++;
            ed = range[i].r;
        }
    }

    cout << cnt << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}