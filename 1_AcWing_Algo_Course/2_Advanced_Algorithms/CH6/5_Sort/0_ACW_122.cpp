// Problem: https://www.acwing.com/problem/content/124/
// 备注：本题目是 ACW105 的前置题目

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n;
int a[N];
LL S[N], A[N];

LL calc(int c[], int n) {
    // 求平均值
    int avg = accumulate(a + 1, a + n + 1, 0ll) / n;
    // 计算每个值与平均值的差距
    for (int i = 1; i <= n; i++)
        A[i] = a[i] - avg;
    // 预处理S数组
    for (int i = 1; i <= n; i++)
        S[i] = S[i - 1] + A[i];
    // 对S排序
    sort(S + 1, S + n + 1);
    LL res = 0;
    // 求出S的中位数mid
    LL mid = S[(n + 1) / 2];  // 向上取整
    // 求出最短距离
    for (int i = 1; i <= n; i++)
        res += abs(mid - S[i]);
    return res;
}

void solve() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    printf("%lld\n", calc(a, n));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}