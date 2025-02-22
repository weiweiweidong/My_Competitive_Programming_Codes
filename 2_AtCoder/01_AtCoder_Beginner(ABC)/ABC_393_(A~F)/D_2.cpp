// Problem: https://atcoder.jp/contests/abc393/tasks/abc393_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;
vector<int> b;

void solve() {
    cin >> n >> s;

    // 找出所有 1 的位置，并计算 b_i 的值
    int i = 0;  // 记录这是出现的第几个 1
    for (int j = 0; j < s.size(); j++)
        if (s[j] == '1') {
            i += 1;              // 遇到'1'的时候，计数+1
            b.push_back(j - i);  // 存储 b_i 的值
        }

    sort(b.begin(), b.end());  // 排序
    int x = b[b.size() / 2];  // 求中位数（如果是偶数个，中间两个任取一个）

    // 开始计算总代价
    LL res = 0;
    for (int bi : b)
        res += abs(bi - x);

    // 输出结果
    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}