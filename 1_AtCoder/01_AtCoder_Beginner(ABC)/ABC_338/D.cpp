#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ls(p) (p << 1)          // 定义左子节点
#define rs(p) (p << 1 | 1)      // 定义右子节点
#define mid ((l + r) >> 1)      // 定义中间位置
#define lowbit(i) ((i) & (-i))  // 定义计算二进制中最低位1的位置
const int inf = 1e18;           // 定义一个正无穷值
const int N = 1e5 + 10;

// 主解题函数
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1), s(n + 1), q(n + 1);

    for (int i = 1; i <= m; i++) {
        cin >> q[i];
        if (i > 1) {
            int x = q[i - 1], y = q[i];
            if (x > y)
                swap(x, y);
            int len1 = y - x;     // 直接距离
            int len2 = n - len1;  // 绕行距离
            s[x] += len2;         // 更新绕行距离到差分数组
            s[y] -= len2;         // 在y处减去绕行距离

            s[1] += len1;
            s[x] -= len1;
            s[y] += len1;
        }
    }
    int ans = inf;
    for (int i = 1; i <= n; i++) {
        s[i] += s[i - 1];  // 计算前缀和，得到每个点的累积路径长度
        ans = min(ans, s[i]);  // 更新最小路径长度
    }

    cout << ans << '\n';
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