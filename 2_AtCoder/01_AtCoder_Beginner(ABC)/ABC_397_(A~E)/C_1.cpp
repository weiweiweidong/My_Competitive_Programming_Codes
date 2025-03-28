// Problem: https://atcoder.jp/contests/abc397/tasks/abc397_c

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;
int num[N], cnt[N];                      // b 表示右边集合中，各个元素的个数
unordered_set<int> num_left, num_right;  // 左边集合，右边集合
int n, x;

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        num[i] = x;           // 保存数字
        cnt[x]++;             // 记录右边集合数字出现的次数
        num_right.insert(x);  // 将元素插入右边的集合
    }

    int res = 0;
    // 遍历每一个数字
    for (int i = 1; i <= n; i++) {
        x = num[i];          // 获取当前数字
        num_left.insert(x);  // 将当前数字插入左边集合
        cnt[x]--;            // 右边集合中数量减少 1
        // 如果当前元素恰好被清空，就从右边集合中清除当前数字
        if (cnt[x] == 0 && num_right.count(x) > 0)
            num_right.erase(x);
        // 记录答案
        res = max(res, (int)(num_left.size() + num_right.size()));
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}