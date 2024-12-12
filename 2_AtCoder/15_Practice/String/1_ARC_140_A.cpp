// Problem: https://atcoder.jp/contests/arc140/tasks/arc140_a

// 贪心
/*
    思路：
    字符串，例如 abcabaacd，我们可以遍历每个子串的长度len。
    根据子串长度，可以将字符串切割成若干段，例如： abc|aba|acd
    如果把这几个子串立起来，就变成了：
        a b c |
        a b a |
        a c d
    我们就可以判断每一列的字符中，最少改多少个，就能变成完全相同：
        a b c |
        a b a |
        a c d
          ↑  这一列，可以知道改变一个字符，就能全部相同
    使用贪心，从头到尾遍历一遍即可。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
string S;
int n, k;
int s[30];

void solve() {
    cin >> n >> k >> S;

    // len 为子串的长度
    for (int len = 1; len <= n; len++) {
        if (n % len == 0) {
            // c 为循环次数（即有多少行）
            int c = n / len;

            int res = 0;
            // 遍历子串的每个字符
            for (int i = 0; i < len; i++) {
                // 记录字母出现次数的 s 数组重置
                memset(s, 0, sizeof s);
                // 计算这一列各个字母的出现次数
                int max_x = -1;
                for (int j = 0; j < c; j++) {
                    char x = S[i + j * len];
                    s[x - 'a']++;
                    max_x = max(max_x, s[x - 'a']);
                }
                res += c - max_x;
            }
            if (res <= k) {
                cout << len << endl;
                break;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}