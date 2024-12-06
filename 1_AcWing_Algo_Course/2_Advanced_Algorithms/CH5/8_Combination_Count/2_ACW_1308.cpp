// Problem: https://www.acwing.com/problem/content/1310/

// 组合数 + 高精度
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 150;

int k, x;
// 三维数组f用于存储组合数计算的中间结果，第三维N用于存储大数的每一位
int f[1000][100][N];

// 快速幂
int qmi(int a, int b, int p) {
    int res = 1;
    while (b) {
        if (b & 1)
            res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

// 高精度加法：a+b 的结果存到 c 中
void add(int c[], int a[], int b[]) {
    for (int i = 0, t = 0; i < N; i++) {
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
}

void solve() {
    cin >> k >> x;

    // 计算 x^x % 1000 的值。因为模的缘故，结果并不会很大
    int n = qmi(x % 1000, x, 1000);

    // 计算 C^{k-1}_{n-1}
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i && j < k; j++)
            if (!j)
                f[i][j][0] = 1;
            else
                // f[i][j] 表示的是 C^{j}_{i} 的意思
                // 备注：f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
                add(f[i][j], f[i - 1][j], f[i - 1][j - 1]);

    // n==0 要特判，不然f[n-1][k-1]会越界
    if (!n) {
        cout << "0" << endl;
        return;
    }

    // 输出结果
    int* g = f[n - 1][k - 1];
    int i = N - 1;
    while (!g[i])  // 跳过前导 0
        i--;
    while (i >= 0)  // 从高位向低位输出
        cout << g[i--];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}