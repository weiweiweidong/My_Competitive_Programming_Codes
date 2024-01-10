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

// 前缀和的使用技巧
int main() {
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    // 构建数组 p
    vector<int> p(N, 0);
    for (int i = 1; i < N; i++) {
        if (S[i] == S[i - 1])
            p[i] = 1;
    }
    // 构建前缀和数组 sum
    vector<int> sum(N, 0);
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + p[i];
    }

    // 进行查询
    while (Q--) {
        int l, r;
        cin >> l >> r;
        cout << sum[r - 1] - sum[l - 1] << endl;
    }
}