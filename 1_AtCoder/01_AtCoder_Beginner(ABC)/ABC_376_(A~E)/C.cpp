// Problem:

// 贪心题目
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int n;
int A[N], B[N], c[N];

// 检查 x 能否让 B 满足条件
// true 表示满足条件，x 偏大，要向左边走
// false 表示不满足条件，x 太小，要向右边走
bool check(int x) {
    for (int i = 1; i < n; i++)
        c[i] = B[i];
    c[n] = x;
    sort(c + 1, c + n + 1);
    for (int i = 1; i <= n; i++)
        // 但凡出现了 false，说明插入的 x 太小了
        if (A[i] > c[i])
            return false;
    return true;
}

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n - 1; i++)
        cin >> B[i];
    // 对 A 升序排序
    sort(A + 1, A + n + 1);

    int l = 1, r = A[n] + 1, ans = -1;
    while (l < r) {
        int mid = (r + l) / 2;
        if (check(mid))
            r = mid, ans = mid;
        else
            l = mid + 1;
    }

    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}