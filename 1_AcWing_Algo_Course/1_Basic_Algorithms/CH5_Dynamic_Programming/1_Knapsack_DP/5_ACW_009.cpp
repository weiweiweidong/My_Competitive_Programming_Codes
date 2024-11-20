// Problem: https://www.acwing.com/problem/content/9/
// 分组背包问题
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int n, m;
int f[N];
// v[i][k] 表示第i组的第k个物品体积
// w[i][k] 表示第i组的第k个物品的价值
// s[i] 表示第i组物品的总数
int v[N][N], w[N][N];
int s[N];

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        for (int j = 1; j <= s[i]; j++)
            // 读入第i组的第j个物品的信息：体积和价值
            cin >> v[i][j] >> w[i][j];
    }

    for (int i = 1; i <= n; i++) {      // 遍历每个组
        for (int j = m; j >= 0; j--) {  // 遍历背包容量
            for (int k = 1; k <= s[i]; k++)
                if (v[i][k] <= j)
                    f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
        }
    }
    cout << f[m] << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}