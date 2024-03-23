// Problem: https://www.acwing.com/problem/content/887/
// 求组合数：打表预处理
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010, MOD = 1e9 + 7;
int c[N][N];
int n, a, b;

// 预处理所有的组合数的值
void init() {
    for (int i = 0; i < N; i++)
        for (int j = 0; j <= i; j++)
            if (!j)
                c[i][j] = 1;
            else
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
}

void solve() {
    init();

    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << c[a][b] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}