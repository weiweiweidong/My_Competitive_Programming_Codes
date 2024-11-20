// Problem: https://www.acwing.com/problem/content/898/
// 最长上升子序列：贪心思路+二分，使用vector实现
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
int a[N];

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<int> q;
    for (int i = 1; i <= n; i++) {
        // 这里的pos就是第一个大于等于 a[i] 的位置
        int pos = lower_bound(q.begin(), q.end(), a[i]) - q.begin();
        if (pos == q.size())
            q.push_back(a[i]);
        else
            q[pos] = a[i];
    }
    cout << q.size() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}