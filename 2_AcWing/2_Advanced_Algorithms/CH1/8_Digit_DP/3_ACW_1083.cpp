// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 11;
int f[N][10];

void init() {
    for (int i = 0; i <= 9; i++)
        f[1][i] = 1;

    for (int i = 2; i < N; i++)
        for (int j = 0; j <= 9; j++)
            for (int k = 0; k <= 9; k++)
                if (abs(j - k) >= 2)
                    f[i][j] += f[i - 1][k];
}

int dp(int n) {
    if (n == 0)
        return 0;

    vector<int> nums;
    while (n) {
        nums.push_back(n % 10);
        n /= 10;
    }

    int res = 0;
    int last = -2;
    for (int i = nums.size() - 1; i >= 0; i--) {
        int x = nums[i];
        // 当 i 为最高位，即 i==nums.size()-1 的时候，j 从 1 开始
        // 如果 i 不是最高位的时候，j从0开始
        for (int j = (i == nums.size() - 1); j < x; j++)
            if (abs(j - last) >= 2)
                res += f[i + 1][j];
        if (abs(x - last) >= 2)
            last = x;
        else
            break;

        if (i == 0)
            res++;
    }

    for (int i = 1; i < nums.size(); i++)
        for (int j = 1; j <= 9; j++)
            res += f[i][j];
    return res;
}

void solve() {
    init();

    int l, r;
    cin >> l >> r;
    cout << dp(r) - dp(l - 1) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}