// Problem: https://www.acwing.com/problem/content/203/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1010;
int primes[N], cnt;
int phi[N];
bool st[N];
int T;       // T 次查询
int a[N];    // 记录所有查询值
int sum[N];  // 记录欧拉函数的前缀和

void get_eulers(int x) {
    // 预处理出所有的欧拉函数值
    phi[1] = 1;
    for (int i = 2; i <= x; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= x / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }

    // 预处理欧拉函数的前缀和
    for (int i = 1; i <= x; i++)
        sum[i] = sum[i - 1] + phi[i];
}

void solve() {
    // 读入 T 组数据
    cin >> T;
    for (int i = 1; i <= T; i++)
        cin >> a[i];

    // 预处理所有欧拉函数值（本题数值范围比较小，直接处理出所有即可）
    get_eulers(N - 1);

    // 输出结果
    for (int i = 1; i <= T; i++) {
        int res = sum[a[i]] * 2 + 1;
        printf("%d %d %d\n", i, a[i], res);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}