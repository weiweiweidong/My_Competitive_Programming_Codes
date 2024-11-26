// Problem: https://www.acwing.com/problem/content/243/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2e5 + 10;
int n;
int a[N];        // 原数组
int tr[N];       // 树状数组
int Lower[N];    // Lower[i] 表示左边比第i个位置小的数的个数
int Greater[N];  // Greater[i] 表示左边比第i个位置大的数的个数

int lowbit(int x) {
    return x & -x;
}
// 将序列中第x个数加上k
void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += k;
}
// 查询序列前x个数的和
int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    // 从左向右，统计每个位置左边比i小的数的个数，统计每个位置左边比i大的数的个数
    for (int i = 1; i <= n; i++) {
        int y = a[i];
        // 已经加入树状数组的数中，统计在区间[y+1,n]的数字出现的次数（比y大的数的个数）
        Greater[i] = sum(n) - sum(y);
        // 已经加入树状数组的数中，统计在区间[1,y-1]的数字出现的次数（比y小的数的个数）
        Lower[i] = sum(y - 1);
        // 将y加入树状数组，即数字y出现1次
        // 即第y个位置+1
        add(y, 1);
    }

    // 再把树状数组清空
    memset(tr, 0, sizeof tr);
    LL res1 = 0, res2 = 0;
    // 开始从右往左计算（此时树状数组为空，一点点从右往左把数据插入树状数组的）
    for (int i = n; i > 0; i--) {
        int y = a[i];
        // 计算V型：左边比y大的数量 * 右边比y大的数量
        res1 += Greater[i] * (LL)(sum(n) - sum(y));
        // 计算^型：左边比y小的数量 * 右边比y小的数量
        res2 += Lower[i] * (LL)(sum(y - 1));
        add(y, 1);
    }

    cout << res1 << " " << res2 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}