// Problem: https://www.acwing.com/problem/content/898/
// 最长上升子序列：贪心思路+二分，使用数组实现
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
int a[N], q[N];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // len 用来存储q的边界
    int len = 0;
    q[0] = -2e9;

    for (int i = 0; i < n; i++) {
        // 找到比a[i]小的最大的数
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (q[mid] < a[i])
                l = mid;
            else
                r = mid - 1;
        }
        len = max(len, r + 1);
        /*
            q[r] 是小于a[i]的最大的数，也就是说：
                 q[r+1]要么不存在，要么大于a[i]。
                 无论怎样，都把q[r+1]更新为 a[i]即可
        */
        q[r + 1] = a[i];
    }

    cout << len << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}