// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 15;
int f[N][N];  // f[i, j]表示一共有i位，且最高位填j的不降数的个数

// 预处理：实际上也是一个 DP
void init() {
    // 一位数的不降数个数均为 1
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;
    // dp 预处理
    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = j; k <= 9; k++)
                f[i][j] += f[i - 1][k];
}

int dp(int n) {
    // 即返回[0,0] 之间的不降数
    if (n == 0)
        return 1;

    // 把nums的每一位摘出来
    vector<int> nums;
    while (n)
        nums.push_back(n % 10), n /= 10;

    int res = 0;
    int last = 0;  // 保存上一位的最大值
    // 从高位向低位遍历
    for (int i = nums.size() - 1; i >= 0; i--) {
        // 当前位的上限为x
        int x = nums[i];

        // 从上一位的最大值last开始，到上限值x
        for (int j = last; j < x; j++)
            res += f[i + 1][j];

        // 如果上一位大于当前位上限值的话，右边分支不存在，直接退出
        if (x < last)
            break;
        // 更新上一位值
        last = x;
        // 最右分支特判
        if (i == 0)
            res++;
    }

    return res;
}

void solve() {
    // 初始化
    init();

    // 读入数据 并 输出结果
    int l, r;
    while (cin >> l >> r)
        cout << dp(r) - dp(l - 1) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}