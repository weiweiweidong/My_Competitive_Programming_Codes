// Problem: https://www.acwing.com/problem/content/205/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 扩展欧几里得算法函数
// 参数 a, b 是输入的两个数
// x, y 是通过引用传递的变量，用于存储方程 ax + by = gcd(a,b) 的一组解
int exgcd(int a, int b, int& x, int& y) {
    // 递归的边界条件：当 b 为 0 时
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    // 递归求解子问题
    int d = exgcd(b, a % b, y, x);
    // 由子问题的解得到原问题的解
    y -= a / b * x;
    // 返回最大公约数
    return d;
}

void solve() {
    int a, b;
    cin >> a >> b;

    int x, y;
    exgcd(a, b, x, y);

    // 输出结果
    // (x % b + b) % b 确保结果在 [0, b) 范围内
    // 使用 LL 避免中间结果溢出
    cout << (x % b + (LL)b) % b << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}