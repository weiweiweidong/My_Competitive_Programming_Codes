#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;
int n, m;
int a[N];
LL tr[N];

int lowbit(int x) {
    return x & -x;
}
void add(int x, int k) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += k;
}
LL sum(int x) {
    LL res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main() {
    // 读入数据
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    // 将差分数组整理进树状数组中
    for (int i = 1; i <= n; i++) {
        add(i, a[i] - a[i - 1]);
    }

    while (m--) {
        // 读入操作
        char op[2];
        scanf("%s", op);
        // 如果操作符是 C
        if (op[0] == 'C') {
            int l, r, d;
            scanf("%d%d%d", &l, &r, &d);
            // 维护差分数组的头和尾两个点
            add(l, d);
            add(r + 1, -d);
        }
        // 如果操作符是 Q
        else {
            int x;
            scanf("%d", &x);
            // 计算差分数组的前缀和
            cout << sum(x) << endl;
        }
    }
}