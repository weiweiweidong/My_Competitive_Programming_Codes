#include <bits/stdc++.h>
using namespace std;
#define int long long
const int inf = 1e18;
const int N = 1e5 + 10;

// 主解题函数
void solve() {
    // 读入所有数据
    int n;
    cin >> n;
    vector<int> A(n + 1), B(n + 1), Q(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> Q[i];
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1; i <= n; i++)
        cin >> B[i];

    int res = 0;
    // 遍历生产a组A产品
    for (int a = 0; a < 1e9; a++) {
        bool flag = false;
        // 看最多能生产多少b
        int b = inf;
        for (int j = 1; j <= n; j++) {
            if (B[j])
                b = min(b, Q[j] / B[j]);
        }
        // 判断一下最大值
        res = max(res, b + a);
        // 看一下剩下的值够不够生产一组A（为下一个循环做准备）
        for (int i = 1; i <= n; i++) {
            if (Q[i] < A[i])
                flag = true;
        }
        // 如果不够，跳出循环
        if (flag)
            break;
        // 如果够，就把材料减去一组A的材料
        for (int i = 1; i <= n; i++)
            Q[i] -= A[i];
    }

    cout << res << endl;
}

signed main() {
    ios::sync_with_stdio(0);  // 加速C++输入输出流
    cin.tie(0), cout.tie(0);  // 解除cin和cout的绑定
    int T = 1;  // 这里可以定义多组测试数据，但在这个代码中默认只有一组
    // cin>>T;
    while (T--)
        solve();  // 循环处理每组测试数据
    return 0;
}