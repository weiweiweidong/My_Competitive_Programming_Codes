// Problem: https://www.acwing.com/problem/content/1305/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 3;
int n, m;

// 计算向量乘以矩阵：a*b=c 的结果
void mul(int c[], int a[], int b[][N]) {
    int temp[N] = {0};
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[i] = (temp[i] + (LL)a[j] * b[j][i]) % m;
    // 将结果拷贝到 c 里面
    memcpy(c, temp, sizeof temp);
}

// 计算矩阵乘以矩阵：a*b=c 的结果
void mul(int c[][N], int a[][N], int b[][N]) {
    int temp[N][N] = {0};

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                temp[i][j] = (temp[i][j] + (LL)a[i][k] * b[k][j]) % m;
    memcpy(c, temp, sizeof temp);
}

void solve() {
    cin >> n >> m;
    int f1[N] = {1, 1, 1};

    int a[N][N] = {{0, 1, 0}, {1, 1, 1}, {0, 0, 1}};

    n--;

    // 快速幂算法
    while (n) {
        if (n & 1)  // 如果 n 的二进制位为 1，则计算结果
            mul(f1, f1, a);
        mul(a, a, a);  // 矩阵自乘
        n >>= 1;       // n 右移一位，相当于除以 2
    }

    cout << f1[2] % m << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
