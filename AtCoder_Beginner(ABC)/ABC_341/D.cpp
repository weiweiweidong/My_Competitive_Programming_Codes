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

typedef long L;
typedef long long LL;
using namespace std;

// 计算最大公约数
LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

// 计算最小公倍数
LL lcm(LL a, LL b) {
    return a / gcd(a, b) * b;
}

// 计算小于等于x的，只被N或M整除的数的数量
LL count(LL x, LL n, LL m) {
    return x / n + x / m - 2 * (x / lcm(n, m));
}

int main() {
    LL n, m, k;
    cin >> n >> m >> k;

    LL left = 1, right = k * max(n, m);

    // 二分搜索
    while (left < right) {
        LL mid = (left + right) / 2;
        if (count(mid, n, m) >= k)
            right = mid;
        else
            left = mid + 1;
    }

    cout << right << endl;
    return 0;
}
