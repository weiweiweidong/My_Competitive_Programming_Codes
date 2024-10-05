// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 35;  // 假设处理位数最大不超过35位
int f[N][N];  // 预处理出来的组合数。f[i][j]表示从i个元素中选出来j个
int K, B;  // K：能用的1的个数；  B：B进制

// 记忆化搜索求组合数
// 预处理出来的组合数。f[i][j]表示从i个元素中选出来j个ss
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            if (!j)
                f[i][j] = 1;
            else
                f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
        }
    }
}

// 求 [0,n] 之间满足条件的数的数量
// 本题满足条件：一个数的B进制表示中，其中有K位是1，其余全是0
int dp(int n) {
    // [0,0]之间满足条件的数个数为0
    if (n == 0)
        return 0;

    vector<int> nums;
    // 相当于一个B进制转换，每一位单独拿出来
    // 例如：n=123，B=10；最后nums=[3,2,1]
    while (n)
        nums.push_back(n % B), n /= B;

    int res = 0;  // 答案
    // last：遍历当前位的时候，记录之前那些位已经占用多少个1，那么当前还能用的1的个数就是K-last
    int last = 0;
    // 从最高位开始遍历每一位
    for (int i = nums.size() - 1; i >= 0; i--) {
        // x为当前位的上限数字
        int x = nums[i];

        // 只有上限值x非0的时候，才有可能讨论左右分支。
        if (x > 0) {
            // 情况1:
            // 当前位填0，从剩下的i位数中选 K-last 个数
            // 对应于左分支为0的情况，合法
            res += f[i][K - last];

            // 情况2:（上限值大于1）
            // 如果当前位上限值大于1，那这一位只能填1
            if (x > 1) {
                // 当前位填1，从剩下的i位数中选 K-last-1 个数填1
                if (K - last - 1 >= 0)
                    res += f[i][K - last - 1];
                break;
            }
            // 情况3:（取到上限值）
            // x==1
            // 的时候，这一位只能填1（只有1种情况，即1被强制使用，更新last）
            else {
                last++;
                // 如果已经填的个数last > 需要填的个数K，说明不合法直接 break
                if (last > K)
                    break;
            }
        }
        // 上面处理完了这棵树的所有左分支，就剩下最后一种右分支的情况
        //  如果已经到了最低位，并且1的数量刚好等于K，那最后一位只能取0
        if (i == 0 && last == K)
            res++;
    }
    return res;
}

void solve() {
    init();
    int l, r;
    cin >> l >> r >> K >> B;
    cout << dp(r) - dp(l - 1) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}