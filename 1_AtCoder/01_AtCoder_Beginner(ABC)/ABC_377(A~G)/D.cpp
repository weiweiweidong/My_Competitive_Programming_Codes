// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MAX_N = 2e5 + 10;

struct node {
    int l, r;
} a[MAX_N];

int n, m;        // n是区间数量，m是范围上限
int ans[MAX_N];  // 区间最近右端点
long long tot;   // 累计最终答案的变量

bool cmp(node x, node y) {
    return x.l > y.l;  // 按照左端点降序排序
}

void solve() {
    // 输入部分
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i].l >> a[i].r;  // 读入n个区间的左右端点

    // 排序 nlogn
    sort(a + 1, a + n + 1, cmp);  // 将区间按左端点降序排序

    // 初始化ans数组
    for (int i = 1; i <= m + 1; i++)
        ans[i] = m + 1;  // 初始化为最大可能值m+1

    // 第一次处理：对于每个位置，找到以该位置为左端点的区间中，右端点最小的值。O(n)
    for (int i = 1; i <= n; i++)
        ans[a[i].l] = min(ans[a[i].l], a[i].r);

    // 第二次处理：从右向左维护最小值 O(m)
    for (int i = m; i >= 1; i--) {
        ans[i] = min(ans[i], ans[i + 1]);  // 确保右边的值不会比当前值小
        tot += (ans[i] - i);  // 累加每个位置到其对应右端点的距离
    }

    cout << tot << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}