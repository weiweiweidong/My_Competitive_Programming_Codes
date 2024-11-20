// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;
int n, m;
LL s[N];
LL q[N];

void solve() {
    // 读入数据，计算前缀和
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }

    LL res = -1e18;
    int hh = 0, tt = 0;
    // 遍历终点
    for (int i = 1; i <= n; i++) {
        // 保证队列中的元素不超过子数组长度限制 m
        if (q[hh] < i - m)
            hh++;
        // 更新最大区间和
        res = max(res, s[i] - s[q[hh]]);
        // 维护单调队列，使内部元素的值单调递增
        // 如果新的值 s[i] 小于 队尾 s[q[tt]]，就弹出队尾元素
        while (hh <= tt && s[q[tt]] >= s[i])
            tt--;
        // 将当前下标加入队列的尾部
        q[++tt] = (LL)i;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}