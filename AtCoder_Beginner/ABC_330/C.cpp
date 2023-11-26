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

typedef long L;
typedef long long LL;
using namespace std;

// 找到一个整数y，使得 y^2 <= x
LL mySqrt(LL x) {
    // 二分解法
    LL l = 0, r = x;
    while (l < r) {
        LL mid = (l + 1LL + r) >>
                 1;  // l+r 有可能会越界。这样写可以将结果转化为LL形式，避免越界
        if (mid <= x / mid)
            l = mid;  // 这样写是为了防止计算 mid * mid 时越界
        else
            r = mid - 1;
    }
    return r;
}

int main() {
    LL D;
    cin >> D;
    LL res = 2e12 + 10;
    for (LL x = 1; x < LL(2e12 + 10) / x; x++) {
        LL temp = D - x * x;
        if (temp >= 0) {
            LL y = mySqrt(D - x * x);
            res = min(res, abs(D - x * x - y * y));
            y++;
            res = min(res, abs(D - x * x - y * y));
        }
    }

    cout << res << endl;
}
