#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;
int n, m;
int a[N];
LL tr1[N];  // 维护 b[i] 的前缀和
LL tr2[N];  // 维护 i*b[i] 的前缀和

int lowbit(int x) {
    return x & -x;
}

void add(LL tr[], int x, LL k) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += k;
}

LL sum(LL tr[], int x) {
    LL res = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        res += tr[i];
    return res;
}

// 计算a[]的前x项的和
LL prefix_sum(int x) {
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

int main() {
    scanf("%d%d", &n, &m);
    // 读入原数组
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    // 初始化树状数组 tr1 和 tr2
    for (int i = 1; i <= n; i++) {
        int b = a[i] - a[i - 1];
        add(tr1, i, b);
        add(tr2, i, (LL)b * i);
    }

    while (m--) {
        char op[2];
        int l, r;
        scanf("%s%d%d", op, &l, &r);
        // 如果操作是 Q
        if (*op == 'Q') {
            cout << prefix_sum(r) - prefix_sum(l - 1) << endl;
        }
        // 如果操作是 C
        else {
            int d;
            scanf("%d", &d);
            // a[l] += d
            add(tr1, l, d), add(tr2, l, l * d);
            // a[r+1] -= d
            add(tr1, r + 1, -d), add(tr2, r + 1, (r + 1) * -d);
        }
    }
    return 0;
}