// Problem: https://atcoder.jp/contests/abc395/tasks/abc395_b

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int M = 1e6 + 10;
int n;
int a;
int res;
int ls[M];  // v 最后出现的位置

void solve() {
    // ls 初始化
    memset(ls, -1, sizeof ls);
    // 读入数据
    cin >> n;
    // 预设一个正无穷值
    res = 1e9;
    // 开始遍历每个数
    for (int i = 0; i < n; i++) {
        cin >> a;
        // 如果这个数出现过
        if (ls[a] != -1) {
            // 更新长度值
            res = min(res, i - ls[a] + 1);
        }
        // 更新当前数字出现的位置
        ls[a] = i;
    }

    // 输出结果
    cout << (res == 1e9 ? -1 : res) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}