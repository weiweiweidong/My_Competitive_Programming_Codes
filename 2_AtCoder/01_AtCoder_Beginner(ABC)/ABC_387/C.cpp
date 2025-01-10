// Problem: https://atcoder.jp/contests/abc387/tasks/abc387_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL L, R;

LL fpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1)
            res = res * a;
        b >>= 1;
        a = a * a;
    }
    return res;
}

// 统计 [1,lx] 之间的蛇形数的个数
LL cal(LL lx) {
    if (lx < 10)
        return 0;

    LL num = 0;
    string x = to_string(lx);
    int high = x[0] - '0';
    LL len = x.size();

    // 情况 1：
    for (int i = 2; i < len; i++)     // 枚举长度
        for (int j = 1; j <= 9; j++)  // 枚举首位
            num += fpow(j, i - 1);

    // 处理相同位数，但是首位更小的情况
    for (int j = 1; j < high; j++)
        num += fpow(j, len - 1);

    // 处理首位相同的情况：从高向低挨个看
    for (int j = 0; j < len; j++) {
        // 如果某一位大于等于high，无论后面是什么数字，都不可能构成蛇形数了
        if (j != 0 && int(x[j] - '0') >= high)
            break;

        // 只看中间的位置
        if (j < len - 1) {
            // 下一位可以取的数就是 min(当前位数字, high)
            num += min(int(x[j + 1] - '0'), high) * fpow(high, len - j - 2);
        }

        // 处理最后一位：如果能处理到最后一位了，说明x本身就是个蛇形数，把自己加上
        if (j == len - 1)
            num += 1;
    }

    return num;
}

void solve() {
    cin >> L >> R;
    cout << cal(R) - cal(L - 1) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}