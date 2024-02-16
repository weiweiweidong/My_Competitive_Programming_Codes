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

const LL mod = 998244353;

int main() {
    // 读入数据
    int n;
    string S;
    cin >> n >> S;

    // 判断S长度能否收敛
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        if (S[i] > '1' && S[i + 1] > '1') {
            flag = true;
            break;
        }
    }

    // 不能收敛
    if (flag)
        cout << -1 << endl;
    // 能收敛
    else {
        LL res = 1;
        // 从后往前遍历，更新res的值
        for (int i = n - 2; i >= 0; i--) {
            res = (res + 1 + (S[i + 1] - '1') * res) % mod;
        }

        // 因为会把最后一位也给删掉，所以这里要把最后一位找回来
        cout << res - 1 << endl;
    }
}