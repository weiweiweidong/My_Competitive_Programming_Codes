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
using namespace std;  // 服了atcoder登不进去盲打代码 题还看不懂

string c[200010];
int as = 1e7, n, m, k, s[200010], S[200010];

int main() {
    // 读入数据
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> c[i], c[i] = ' ' + c[i];

    // 处理每一行
    for (int i = 1; i <= n; i++) {
        // 前缀和：求前面有多少个 o
        for (int j = 1; j <= m; j++)
            s[j] = s[j - 1] + (c[i][j] == 'o');
        // 前缀和：求前面有多少个 x
        for (int j = 1; j <= m; j++)
            S[j] = S[j - 1] + (c[i][j] == 'x');
        // 检查每个长度为 k 的子串
        for (int j = k; j <= m; j++) {
            // 如果包含x，就跳过
            if (S[j] - S[j - k])
                continue;
            // 计算需要多少次操作将.变成o
            as = min(as, k - (s[j] - s[j - k]));
        }
    }

    // 处理每一列
    for (int j = 1; j <= m; j++) {
        // 前缀和：求上面有多少个o
        for (int i = 1; i <= n; i++)
            s[i] = s[i - 1] + (c[i][j] == 'o');
        // 前缀和：求上面有多少个x
        for (int i = 1; i <= n; i++)
            S[i] = S[i - 1] + (c[i][j] == 'x');
        // 检查每个长度为k的子串
        for (int j = k; j <= n; j++) {
            // 如果包含x，就跳过
            if (S[j] - S[j - k])
                continue;
            // 计算需要多少次操作将.变成o
            as = min(as, k - (s[j] - s[j - k]));
        }
    }
    if (as == 1e7)
        as = -1;
    cout << as;
    return 0;
}