// Problem: https://atcoder.jp/contests/abc380/tasks/abc380_d

// 这是一道非常典型的递归题目
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

string s;
int t;

// 大小写转换
// ascii 码中：A 为65，a 为 97，相差 32
char change(char ch) {
    return ch >= 'a' ? (ch - 32) : (ch + 32);
}

// 递归
char f(LL x, bool is_reverse) {
    // 如果已经到了最前面
    if (x <= s.size()) {
        // 如果需要翻转
        if (is_reverse)
            return change(s[x - 1]);
        // 不需要翻转
        else
            return s[x - 1];
    }

    LL k = s.size();
    // 找到距离 x 左边最近的倍数
    while (k * 2 < x)
        k *= 2;
    // 减去这个长度，向前找
    return f(x - k, !is_reverse);
}

void solve() {
    cin >> s >> t;
    while (t--) {
        LL x;
        cin >> x;
        cout << f(x, false) << " ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}