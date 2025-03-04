// Problem: https://atcoder.jp/contests/abc395/tasks/abc395_a

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 110;
int n;
int a[N];

void solve() {
    // 读入数据
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // 开始遍历每个数
    bool flag = false;
    for (int i = 1; i < n; i++)
        // 只要出现 前面的数字 大于等于 后面的数字，flag 标记
        if (a[i - 1] >= a[i])
            flag = true;

    // 只要有标记，说明不严格递增
    if (flag)
        cout << "No" << endl;
    // 否则就严格递增
    else
        cout << "Yes" << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}