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
    int N;
    cin >> N;
    vector<int> A(N);
    for (int& x : A)
        cin >> x;

    vector<int> dp(N);
    dp[0] = 1;  // 因为每个数最少都为1，极限情况下只有一个数字
    // 正向计算每个位置有可能达到的最大高度
    for (int i = 1; i < N; i++) {
        dp[i] = min(dp[i - 1] + 1, A[i]);
    }

    int now = 0;  // 当前处理的元素能构成的金字塔的最大高度
    int res = 1;  // 整个序列能构成的金字塔的最大高度
    for (int i = N - 1; i >= 0; i--) {
        now = min(now + 1, A[i]);
        res = max(res, min(now, dp[i]));
    }
    cout << res << endl;
}