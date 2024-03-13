// Problem: https://www.acwing.com/problem/content/833/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, M = 1e6 + 10;
int n, m;
char S[M], P[N];
int ne[N];

void solve() {
    cin >> n >> (P + 1) >> m >> (S + 1);

    // 预处理 next 数组
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && P[i] != P[j + 1])
            j = ne[j];
        if (P[i] == P[j + 1])
            j++;
        ne[i] = j;
    }
    // 模式串P 与 字符串S 匹配
    for (int i = 1, j = 0; i <= m; i++) {
        while (j && S[i] != P[j + 1])
            j = ne[j];
        if (S[i] == P[j + 1])
            j++;
        if (j == n) {
            cout << i - n << " ";
            j = ne[j];
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}