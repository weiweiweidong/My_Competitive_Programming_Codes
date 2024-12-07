#include <math.h>
#include <algorithm>
#include <cstring>
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
using namespace std;

typedef long L;
typedef long long LL;
typedef pair<int, int> PII;

vector<LL> p;

int main() {
    LL n;
    cin >> n;
    LL m = sqrt(n);
    vector<bool> f(m + 1, false);

    // 埃式筛法，预处理质数数组
    for (LL i = 2; i <= m; i++) {
        if (!f[i]) {
            p.push_back(i);
            for (LL j = i + i; j <= m; j += i)
                f[j] = true;
        }
    }

    // 开始遍历所有可能解
    int res = 0;
    for (int i = 0; p[i] * p[i] * p[i] * p[i] * p[i] <= n; i++) {
        for (int j = i + 1; p[i] * p[i] * p[j] * p[j] * p[j] <= n; j++) {
            for (int k = j + 1; p[i] * p[i] * p[j] * p[k] * p[k] <= n; k++)
                res++;
        }
    }
    cout << res << endl;
    return 0;
}