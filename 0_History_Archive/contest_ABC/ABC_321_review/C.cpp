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

// 满足 321-like 类型的数字不会很多。最大值就是 9876543210。
// 容易知道，0～9 的所有子集，都恰好能构成一个满足条件的数字。总共有 2^10=1024
// 种可能性。再扣除 空集 和 0 两种可能性，所以只有 1022 个满足条件的数字

int main() {
    vector<long long> all;
    for (int i = 1; i < 1024; i++) {
        long long val = 0;
        for (int j = 0; j < 10; j++) {
            if ((i >> j) & 1) {
                val = val * 10 + (9 - j);
            }
        }
        all.push_back(val);
    }
    sort(all.begin(), all.end());
    int K;
    cin >> K;
    cout << all[K] << '\n';
}