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

typedef long long LL;
typedef pair<int, int> PII;

LL temp[200010];

// 将数字x简化，结果为：若干个奇数次的质数相乘
LL f(LL x) {
    unordered_map<LL, LL> h;
    LL res = 1;
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            LL cnt = 0;
            while (x % i == 0) {
                cnt++;
                x /= i;
            }
            // 如果出现了奇数次
            if (cnt % 2)
                res *= i;
        }
    }
    // 如果最后剩下了一个数：
    if (x > 1)
        res *= x;
    return res;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N + 1);

    LL ans = 0, zeroCount = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        // 如果这个数字为0，它可以和前面所有的数字搭配
        if (A[i] == 0) {
            ans += i - 1;
            zeroCount++;
            continue;
        }

        LL x = f(A[i]);
        ans += temp[x] + zeroCount;
        temp[x]++;
    }

    cout << ans << endl;
}