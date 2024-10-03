// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 55, M = 35, INF = 1e9;
int n;
int w[N];
LL f[N][N][M];  // 前面的 f[N][N] 是DP用的。第三个M维度是存储 M位大数用

// 大数加法
// a和b都是低位向高位存储。（例：1742，在a中为 a=[2,4,7,1]）
void add(LL a[], LL b[]) {
    static LL c[M];
    memset(c, 0, sizeof c);
    for (int i = 0, t = 0; i < M; i++) {
        t += a[i] + b[i];
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);  // 将计算结果从临时数组c复制到a里面
}
// 大数乘法
void mul(LL a[], LL b) {
    static LL c[M];
    memset(c, 0, sizeof c);
    LL t = 0;
    for (int i = 0; i < M; i++) {
        t += a[i] * b;
        c[i] = t % 10;
        t /= 10;
    }
    memcpy(a, c, sizeof c);  // 将计算结果从临时数组c复制到a里面
}
// 对两个大整数数组进行比较
int cmp(LL a[], LL b[]) {
    // 从高位向低位比较
    for (int i = M - 1; i >= 0; i--)
        if (a[i] > b[i])
            return 1;  // 表示 a大于b
        else if (a[i] < b[i])
            return -1;  // 表示 a小于b
    return 0;           // 表示 a等于b
}
// 打印当前大数
void print_f(LL a[]) {
    int k = M - 1;
    while (k && !a[k])
        k--;
    while (k >= 0)
        cout << a[k--];
    cout << endl;
}

void solve() {
    // 数据读入
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    // 大数 temp
    LL temp[M];
    // 第一层循环：遍历区间长度
    for (int len = 3; len <= n; len++)
        // 第二层循环：遍历起始点
        for (int l = 1; l + len - 1 <= n; l++) {
            // 确定终点
            int r = l + len - 1;
            f[l][r][M - 1] = 1;
            // 第三层循环：便利分界点
            for (int k = l + 1; k < r; k++) {
                memset(temp, 0, sizeof temp);
                temp[0] = w[l];
                mul(temp, w[k]);
                mul(temp, w[r]);
                add(temp, f[l][k]);
                add(temp, f[k][r]);
                if (cmp(f[l][r], temp) > 0)
                    memcpy(f[l][r], temp, sizeof temp);
            }
        }

    print_f(f[1][n]);
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}