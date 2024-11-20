// Problem:

// Tag：动态规划，维度缩减

/*
思路：
每个队伍的目标能力值可以计算得到：sum/3

Naive DP:
dp[i][a][b][c]表示将前 i 个人分到三个队伍里，三个队伍的力量值分别为 a b c，
则最少移动多少人。状态转移方程为：
dp[i][a][b][c] = min( dp[i-1][a-s[i]][b][c] + (team[i] != 1),
dp[i-1][a][b-s[i]][c] + (team[i] != 2) , dp[i-1][a][b][c-s[i]] + (team[i] != 3))
容易知道：sum/3 <= 500
总状态数量：N(500^3) = 1.25e10
这个状态数量太大，考虑缩减掉一个维度。

技巧：检查动态规划中有没有“多余的维度”
    容易知道，a+b+c 一定是前 i 个人的力量之和
    所以 c 其实是 sum_s[i] - a - b，因此可以省略掉一个维度

Optimized DP：
dp[i][a][b] 表示将前 i 个人分到三个队伍中，三个队伍的力量值分别为 a b
sum_s[i]-a-b，最少移动几个人。 状态转移方程为： dp[i][a][b] = min(
dp[i-1][a-s[i]][b] + (team[i] != 1) , dp[i-1][a][b-s[i]] + (team[i] != 2) ,
dp[i-1][a][b] + (team[i] != 3))
总状态数量为 N(500^2) = 2.5e7，是可以接受的程度
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 120;
int n;
int team[N], s[N];    // 存储每个人的 组 和 能力
int s_sum;            // 计算总和
int s_prefix_sum[N];  // 前缀和
int dp[N][510][510];
/*
技巧：如何快速计算占用内存：
一个 int 占 4 个字节，dp[N][510][510] 就占用 120*510*510*4=1.2e8 字节
1.2e8 / 1024 = 1.2e5 KB
1.2e5 / 1024 = 120 MB
*/

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> team[i] >> s[i];
        s_sum += s[i];
        s_prefix_sum[i] = s_prefix_sum[i - 1] + s[i];  // 前缀和
    }

    // 如果不能被 3 整除，无解
    if (s_sum % 3 != 0) {
        cout << -1 << endl;
        return;
    }

    // 初始化
    memset(dp, 0x3f, sizeof dp);
    dp[0][0][0] = 0;

    // 1 层循环：遍历 n 个人
    for (int i = 1; i <= n; i++) {
        // 2 层循环：遍历队伍 a 的可能值
        for (int a = 0; a <= min(s_sum / 3, s_prefix_sum[i]); a++)
            // 3 层循环：遍历队伍 b 的可能值
            for (int b = 0; b <= min(s_sum / 3, s_prefix_sum[i]); b++) {
                // 找到最小值
                int res = 0x3f3f3f3f;
                if (a >= s[i])
                    res = min(res, dp[i - 1][a - s[i]][b] + (team[i] != 1));
                if (b >= s[i])
                    res = min(res, dp[i - 1][a][b - s[i]] + (team[i] != 2));
                if (s_prefix_sum[i] - a - b >= s[i])
                    res = min(res, dp[i - 1][a][b] + (team[i] != 3));
                dp[i][a][b] = res;
            }
    }

    int ans = dp[n][s_sum / 3][s_sum / 3];
    // 如果压根没有被更新到，说明无解
    // 为什么会没被更新到？举一个反例
    // 4 个人能量值分别为 1 1 1 6，总数能被 3 整除，但是没办法分成 3 3 3 组
    if (ans == 0x3f3f3f3f)
        ans = -1;
    cout << ans << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}