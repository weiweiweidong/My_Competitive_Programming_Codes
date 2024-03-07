#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;
int n;
int h[N];
int ans[N];
int tr[N];

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

int main() {
    // 读入数据
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
        scanf("%d", &h[i]);
    // 树状数组初始化，每个数都是1
    for (int i = 1; i <= n; i++)
        add(i, 1);
    // 从后往前开始找
    for (int i = n; i; i--) {
        // 即：要找到剩下的身高中，第k小的数字
        int k = h[i] + 1;
        int l = 1, r = n;
        // 找到最小的x，使得第一次大于等于k
        while (l < r) {
            int mid = (l + r) >> 1;
            if (sum(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        // 更新结果
        ans[i] = r;
        // 删掉这个数字
        add(r, -1);
    }
    // 按顺序输出
    for (int i = 1; i <= n; i++)
        printf("%d\n", ans[i]);
}