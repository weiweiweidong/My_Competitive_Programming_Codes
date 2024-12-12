// Problem: https://atcoder.jp/contests/abc363/tasks/abc363_f

// DFS
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

LL N;

string dfs(LL n) {
    string s = to_string(n);
    string s_rev = s;
    reverse(s_rev.begin(), s_rev.end());
    int len = s.size();
    bool zero_flag = false;

    // 遍历看中间有没有 0 出现（因为我们想要的数中不能有0）
    for (int i = 0; i < len; i++)
        if (s[i] == '0')
            zero_flag = true;

    // 如果没有 0 出现，并且是回文，直接返回
    if (!zero_flag && s == s_rev)
        return s;
    for (int i = 2, l = sqrt(n); i <= l; i++) {
        if (n % i == 0) {
            bool flag = true;
            int t = i, j = 0;
            // 看看t里面是否有0（因为我们想要的数中不能有0）
            while (t) {
                if (t % 10 == 0)
                    flag = false;
                t /= 10;
            }
            t = i;
            // 中间出现 0 了，直接跳过
            if (!flag)
                continue;
            // 算出计算和 i 对称的数 j
            while (t)
                j = j * 10 + t % 10, t /= 10;
            // 如果找到了这一对对称的数，就继续往下面搜
            if ((n / i) % j == 0) {
                string ret = dfs(n / i / j);
                // 如果得到的结果不是空串
                if (ret != "")
                    return to_string(i) + "*" + ret + "*" + to_string(j);
            }
        }
    }
    return "";
}

void solve() {
    cin >> N;
    string ret = dfs(N);
    if (ret != "")
        cout << ret << endl;
    else
        cout << -1 << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}