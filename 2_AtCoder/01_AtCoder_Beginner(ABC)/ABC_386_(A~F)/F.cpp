// Problem: https://atcoder.jp/contests/abc386/tasks/abc386_f

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 5e5 + 10;

string S, T;
int K;
int f[N][60];

int get_dp(int i, int j) {
    if (abs(i - j) > K)
        return 0x3f3f3f3f;
    // 偏置
    return f[i][j - i + 30];
}

void solve() {
    cin >> K >> S >> T;
    int slen = S.size(), tlen = T.size();

    S = " " + S;
    T = " " + T;

    // f 数组初始化为正无穷
    memset(f, 0x3f, sizeof f);

    /* 设置初始边界 */
    // 对应原来的 f[0][0]：即将空串转化为空串需要 0 步操作
    f[0][30] = 0;
    // 将空串变成长度为 i 的串，需要 i 步插入操作
    for (int i = 1; i <= K; i++)
        f[0][30 + i] = i;
    // 将长度为 i 的串变成空串，需要 i 步删除操作
    for (int i = 1; i <= K; i++)
        f[i][30 - i] = i;

    /* DP */
    // 遍历 S 的每一位
    for (int i = 1; i <= slen; i++) {
        // 遍历偏置
        for (int x = 0; x < 60; x++) {
            // 还原出真正的 j
            /*
                原理：j 只能在[i-30,i+30]范围内，所以下界 j>=i-30
                这里加入了偏置 x 去掉了等号
                即 j = i - 30 + x
            */
            int j = i - 30 + x;
            // 如果 j 超出了范围
            if (j <= 0 || j > tlen)
                continue;

            int cur_dp = 0x3f3f3f3f;
            // S 删除一个字符
            cur_dp = min(cur_dp, get_dp(i - 1, j) + 1);
            // S 添加一个字符（即，T 删除一个字符）
            cur_dp = min(cur_dp, get_dp(i, j - 1) + 1);

            int c = 1;
            if (S[i] == T[j])
                c = 0;
            // S 替换一个字符 或者 不操作
            cur_dp = min(cur_dp, get_dp(i - 1, j - 1) + c);
            // 更新 f
            f[i][x] = cur_dp;
        }
    }

    // 输出结果
    if (get_dp(slen, tlen) <= K)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}