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

map<LL, LL> dp;
LL cal(LL x) {
    if (x == 1)
        return 0;
    if (dp.count(x))
        return dp[x];

    dp[x] = cal(x / 2) + cal((x + 1) / 2) + x;
    return dp[x];
}

int main() {
    LL x;
    cin >> x;

    cout << cal(x) << endl;
}
