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

const LL INF = 1e18;
const int MAX_V = 100001;

int main() {
    int N;
    cin >> N;
    // 记录总共有多少个席位
    int sum_Z = 0;
    vector<LL> dp(MAX_V, INF);
    dp[0] = 0;

    // 开始读入每个选区的数据s
    for (int i = 1; i <= N; i++) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        sum_Z += Z;
        // 如果青木人数多，记录从青木处转来多少人。也就是cost成本
        int weight = max(0, (Y - X + 1) / 2);
        // 记录能获得的价值value（席位数）
        int value = Z;
        for (int i = MAX_V - 1; i >= value; i--) {
            // dp[i] 表示：恰好要获得i个席位，最少要转来多少人
            dp[i] = min(dp[i], dp[i - value] + weight);
        }
    }
    cout << *min_element(dp.begin() + sum_Z / 2 + 1, dp.end()) << endl;
}