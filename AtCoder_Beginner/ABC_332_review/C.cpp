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

int main() {
    int N, M;
    string S;

    // 从标准输入读取天数N，普通T恤数量M和计划字符串S
    cin >> N >> M >> S;

    // 表示当前有 white 件白T，和 logo 件 T恤
    int white = M, logo = 0;
    S += '0';
    // 用来存储logo的最小值。
    int res = 1e9;
    for (int i = 0; i < N + 1; i++) {
        if (S[i] == '0') {
            // 清洗所有的衣服
            res = min(res, logo);
            white = M;
            logo = 0;
        } else if (S[i] == '1') {
            if (white > 0)
                white--;
            else
                logo--;
        } else if (S[i] == '2') {
            logo--;
        }
    }
    cout << -res << endl;

    return 0;
}
