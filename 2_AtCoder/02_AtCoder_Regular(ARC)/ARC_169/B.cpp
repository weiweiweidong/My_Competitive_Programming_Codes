#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

// typedef long L;
// typedef long long LL;
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int N = 2.5e5 + 1;
const int mod = 998244353;

ll preSum[N];
ll dp[N];

int main(int argc, const char* argv[]) {
    int n;
    ll s;
    scanf("%d%lld", &n, &s);
    for (int i = 1; i <= n; ++i) {
        int x;
        scanf("%d", &x);
        // 计算前缀和
        preSum[i] = preSum[i - 1] + x;
    }

    ll ans = 0;
    int j = 0;
    for (int i = 1; i <= n; ++i) {
        while (preSum[i] - preSum[j] > s) {
            ++j;
        }
        dp[i] = dp[j] + i;
        ans += dp[i];
    }
    printf("%lld\n", ans);
    return 0;
}
