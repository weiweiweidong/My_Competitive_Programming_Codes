// Problem: https://www.acwing.com/problem/content/340/
// 计数问题
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 计算整数n有多少位
int dgt(int n) {
    int res = 0;
    while (n)
        res++, n /= 10;
    return res;
}

// 计算 1～n 的整数中，数字x出现了多少次
int cnt(int n, int x) {
    int res = 0, d = dgt(n);

    // 从右到左（从n的低位到高位）枚举每一位，计算x出现的次数
    for (int j = 1; j <= d; j++) {
        int p = pow(10, j - 1);
        int left = n / p / 10, right = n % p, dj = n / p % 10;

        // 1. 计算 xxx<abc 的情况
        if (x != 0)  // 此时left可以取0
            res += left * p;
        if (x == 0 && left != 0)  // x=0时，left不能为0
            res += (left - 1) * p;

        // 2. 计算 xxx=abc 的情况
        if ((dj > x) && (x || left))
            res += p;
        if ((dj == x) && (x || left))
            res += right + 1;
    }
    return res;
}

void solve() {
    int a, b;
    while (cin >> a >> b, a) {
        if (a > b)
            swap(a, b);
        for (int i = 0; i <= 9; ++i)
            cout << cnt(b, i) - cnt(a - 1, i) << ' ';
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}