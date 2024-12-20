// Problem: https://atcoder.jp/contests/abc379/tasks/abc379_e

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 22e6 + 10;
LL a[N];  // 存储字符串每一位的原数字
LL b[N];  // 存储前缀和
int n;    // 字符串长度
string s;

void solve() {
    // 读入数据
    cin >> n >> s;

    // 将每一位转化为数字，存在 a 数组中
    // 并且将 0-base 转化为 1-base
    for (int i = 1; i <= n; i++)
        a[i] = s[i - 1] - '0';

    // 计算每一位，对该位置的权重
    for (int i = 1; i <= n; i++)
        b[i] = a[i] * i;

    // 计算前缀和
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];

    // 从后往前，对每一位进行大数进位
    for (int i = n; i >= 1; i--) {
        // 计算进位
        b[i - 1] += b[i] / 10;
        // 求出当前位的数值
        b[i] %= 10;
    }

    // b[0] 存储最后的进位
    if (b[0] != 0)
        cout << b[0];
    // 从高位到低位输出
    for (int i = 1; i <= n; i++)
        cout << b[i];
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}