// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 100010;
int row[N], col[N], s[N], c[N];

LL work(int n, int a[]) {
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    // 若不能整除，则无解
    if (s[n] % n)
        return -1;

    // 求平均值
    int avg = s[n] / n;

    c[1] = 0;
    for (int i = 2; i <= n; i++)
        c[i] = s[i - 1] - (i - 1) * avg;

    sort(c + 1, c + n + 1);
    LL res = 0;
    LL mid = c[(n + 1) / 2];
    for (int i = 1; i <= n; i++)
        res += abs(c[i] - mid);

    return res;
}

void solve() {
    int n, m, cnt;
    scanf("%d%d%d", &n, &m, &cnt);

    while (cnt--) {
        int x, y;
        scanf("%d%d", &x, &y);
        row[x]++, col[y]++;
    }

    // 求行和列的答案
    LL r = work(n, row);
    LL c = work(m, col);

    // 判断输出结果
    if (r != -1 && c != -1)
        printf("both %lld\n", r + c);
    else if (r != -1)
        printf("row %lld\n", r);
    else if (c != -1)
        printf("column %lld\n", c);
    else
        printf("impossible\n");
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}