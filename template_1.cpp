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
void solve() {}

signed main() {
    ios::sync_with_stdio(0);  // 加速C++输入输出流
    cin.tie(0), cout.tie(0);  // 解除cin和cout的绑定
    int T = 1;  // 这里可以定义多组测试数据，但在这个代码中默认只有一组
    // cin>>T;
    while (T--)
        solve();  // 循环处理每组测试数据
    return 0;
}