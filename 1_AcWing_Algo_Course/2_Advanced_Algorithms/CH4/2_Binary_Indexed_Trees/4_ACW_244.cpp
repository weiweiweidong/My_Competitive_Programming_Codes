// Problem: https://www.acwing.com/problem/content/245/

// 树状数组 + 二分
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int n;
int h[N];    // 存原始数据
int res[N];  // 存结果
int tr[N];   // 树状数组

int lowbit(int x) {
    return x & -x;
}

void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += k;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

void solve() {
    cin >> n;
    // 读入数据
    for (int i = 2; i <= n; i++)
        cin >> h[i];
    // 初始化树状数组
    for (int i = 1; i <= n; i++)
        add(i, 1);

    // 从后往前遍历
    for (int i = n; i; i--) {
        // 提取出排名
        int k = h[i] + 1;

        // 二分：使得第一次大于等于k的最小的数字 x
        int l = 1, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (sum(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }

        // 记录结果
        res[i] = l;
        // 树状数组删掉这个数字
        add(l, -1);
    }

    // 按顺序输出
    for (int i = 1; i <= n; i++)
        cout << res[i] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}