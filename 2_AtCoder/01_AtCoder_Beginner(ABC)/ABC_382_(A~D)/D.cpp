// Problem: https://atcoder.jp/contests/abc382/tasks/abc382_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<vector<int>> res;
vector<int> temp;

void dfs(int x, int u) {
    // 当前序列长度达到n时
    if (u == n) {
        res.push_back(temp);  // 保存当前解
        return;
    }

    // 超出界限，直接返回
    if (x > m)
        return;

    // 从x+10开始遍历，确保相邻数字差值至少为10
    for (int i = x + 10; i <= m - 10 * (n - 1 - u); i++) {
        temp.push_back(i);
        dfs(i, u + 1);
        temp.pop_back();
    }
}

void solve() {
    cin >> n >> m;

    // 从1开始遍历数列 A 的第一个可能数字
    for (int i = 1; i <= m - 10 * (n - 1); i++) {
        temp.push_back(i);
        dfs(i, 1);  // 已经放入一个数，所以u从1开始
        temp.pop_back();
    }

    // 输出每一组解
    cout << res.size() << endl;
    for (auto& x : res) {
        for (auto t : x)
            cout << t << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
