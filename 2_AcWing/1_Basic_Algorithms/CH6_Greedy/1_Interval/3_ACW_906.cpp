// Problem: https://www.acwing.com/problem/content/908/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
struct Range {
    int l, r;
} ranges[N];

bool cmp(Range a, Range b) {
    return a.l < b.l;
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        ranges[i] = {l, r};
    }
    // 按照左端点排序
    sort(ranges, ranges + n, cmp);

    int cnt = 0;
    priority_queue<int, vector<int>, greater<int>> heap;  // 小根堆
    // 挨个遍历所有区间
    for (int i = 0; i < n; i++) {
        auto range = ranges[i];
        // 如果heap是空的    或者
        // 所有组中最小的 max_r 大于等于当前区间的left，就新开一个组
        if (heap.empty() || heap.top() >= range.l)
            heap.push(range.r);
        // 否则就把当前区间加到 max_r 最小的那个组里，更新 max_r
        else {
            heap.pop();
            heap.push(range.r);
        }
    }
    cout << heap.size() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}