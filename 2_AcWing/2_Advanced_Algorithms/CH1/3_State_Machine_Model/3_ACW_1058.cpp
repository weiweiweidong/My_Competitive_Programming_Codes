// Problem: https://www.acwing.com/problem/content/1060/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int n;
int w[N];
int f[N][3];

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    // 初始化
    // 后续状态完全由前面状态转移过来，初不初始化后面状态不会影响结果，所以只需要初始化第一个状态
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;

    // 状态机DP
    for (int i = 1; i <= n; i++) {
        f[i][0] = max(f[i - 1][0], f[i - 1][2]);         // 空仓，未冷冻
        f[i][1] = max(f[i - 1][1], f[i - 1][0] - w[i]);  // 持仓
        f[i][2] = f[i - 1][1] + w[i];                    // 空仓，冷冻
    }

    // 输出结果
    cout << max(f[n][0], f[n][2]) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}