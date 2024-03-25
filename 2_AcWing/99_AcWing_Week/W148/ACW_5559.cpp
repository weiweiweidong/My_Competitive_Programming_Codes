// Problem: https://www.acwing.com/problem/content/5562/
// 双指针做法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3e5 + 10;
int n, k;
int w[N];

void solve() {
    // 读入数据
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> w[i];

    int len = 0, st = 0;
    for (int i = 0, zero = 0, j = 0; i < n; i++) {
        if (w[i] == 0)
            zero++;
        // 只要0的数量超了，尾部指针向前走
        while (zero > k) {
            if (w[j] == 0)
                zero--;
            j++;
        }
        // 如果区间长度超过len了，就记录下新的最大值
        if (i - j + 1 > len) {
            len = i - j + 1, st = j;
        }
    }
    // 把区间内值改为1
    for (int i = st; i < st + len; i++)
        w[i] = 1;

    // 输出结果
    cout << len << endl;
    for (int i = 0; i < n; i++)
        cout << w[i] << " ";
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}