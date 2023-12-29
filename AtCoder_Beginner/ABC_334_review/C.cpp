#include <math.h>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long L;
typedef long long LL;
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> A(K);  // 用于存储缺少袜子的编号，升序排列
    for (int& x : A) {
        cin >> x;
    }
    int ans = 0;

    // 如果 K 为奇数
    if (K % 2) {
        vector<int> dp(K);
        for (int i = 1; i < K; i += 2) {
            dp[i + 1] = A[i] - A[i - 1];
            if (i > 1) {
                dp[i + 1] += dp[i - 1];
            }
        }
        ans = dp[K - 1];
        int now = 0;
        for (int i = K - 2; i >= 0; i -= 2) {
            now += A[i + 1] - A[i];
            ans = min(ans, now + dp[i - 1]);
        }
    }
    // 如果 K 为偶数
    else {
        for (int i = 1; i < K; i += 2) {
            ans += A[i] - A[i - 1];
        }
    }
    cout << ans << '\n';
}