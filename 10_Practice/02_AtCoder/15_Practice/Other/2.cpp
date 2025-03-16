#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> profits(n);
    for (int i = 0; i < n; i++) {
        cin >> profits[i];
    }

    // dp[i] = 选择位置i时能获得的最大收益
    vector<int> dp(n);

    // 对每个位置进行处理
    for (int i = 0; i < n; i++) {
        // 初始情况：只选择位置i
        dp[i] = profits[i];

        // 尝试与之前的位置组合
        for (int j = 0; j < i; j++) {
            // 如果位置j与位置i的距离满足要求
            if (i - j >= k) {
                dp[i] = max(dp[i], dp[j] + profits[i]);
            }
        }
    }

    // 找出最大收益
    int maxProfit = 0;
    for (int i = 0; i < n; i++)
        maxProfit = max(maxProfit, dp[i]);

    cout << maxProfit << endl;

    return 0;
}