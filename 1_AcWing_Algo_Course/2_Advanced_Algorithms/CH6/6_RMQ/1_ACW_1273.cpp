// Problem:

// 使用稀疏表（Sparse Table）来快速解决区间最大值查询问题（RMQ，Range Maximum
// Query）
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 200010, M = 18;  // M 取 log_2(N) 的最大值
int n, m;
int w[N];
int f[N][M];

// 初始化稀疏表
void init() {
    for (int j = 0; j < M; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            if (!j)
                f[i][j] = w[i];
            else
                f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

// 区间查询
int query(int l, int r) {
    int len = r - l + 1;
    int k = log(len) / log(2);

    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    init();

    scanf("%d", &m);
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", query(l, r));
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}