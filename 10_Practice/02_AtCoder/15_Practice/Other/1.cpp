#include <iostream>
#include <vector>
using namespace std;

int main() {
    int target, n;
    cin >> target >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    // dp[i]表示组成和为i的排列个数
    vector<long long> dp(target + 1, 0);

    // 初始化：空集的和为0，只有1种方案
    dp[0] = 1;

    // 动态规划过程
    for (int i = 1; i <= target; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= nums[j]) {
                dp[i] += dp[i - nums[j]];
            }
        }
    }

    cout << dp[target] << endl;

    return 0;
}