// Problem: https://atcoder.jp/contests/abc383/tasks/abc383_d

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const LL N = 2e6 + 10;
LL primes[N], cnt;
bool st[N];
LL n;

// 线性筛法模板
void get_primes(LL x) {
    for (LL i = 2; i <= x; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (LL j = 0; primes[j] * i <= x; j++) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

// 计算 x^4 的值
LL pow_4(LL x) {
    return x * x * x * x;
}

void solve() {
    // 读入数据，计算平方根
    cin >> n;
    LL intSqrt = sqrt(n) + 1;

    // 预处理质数表
    get_primes(intSqrt);

    // 讨论 1*8 的情况
    int res = 0;
    for (int i = 0; i < cnt; i++) {
        if (pow_4(primes[i]) < intSqrt)
            res++;
        // 防止溢出，超出界限直接 break，后面的再不算了
        else
            break;
    }

    // 讨论 3*3 的情况
    for (int i = 0; i < cnt; i++)
        for (int j = i + 1; j < cnt; j++) {
            LL temp = primes[i] * primes[j];
            if (temp < intSqrt)
                res++;
            // 防止溢出，超出界限直接 break
            else
                break;
        }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}