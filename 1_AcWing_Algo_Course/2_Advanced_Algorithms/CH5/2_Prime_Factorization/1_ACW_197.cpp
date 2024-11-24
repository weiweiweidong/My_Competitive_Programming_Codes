// Problem: https://www.acwing.com/problem/content/199/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n;
int primes[N], cnt;
bool st[N];

// 线性筛法模板
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve() {
    cin >> n;

    // 线性筛法，求出 n 以内的所有质数
    get_primes(n);

    // 对于每一个质数，计算在 n！中的幂次
    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        int s = 0;
        for (int j = n; j; j /= p)
            s += j / p;
        cout << p << " " << s << endl;
    }
}

/*
备注：
for (int j = n; j; j /= p)
    s += j / p;
这两行代码可能难以理解。举一个例子：
令 n=12。求 12！的所有质因子。先看一下质因子 2：
    // j=12: 12/2 = 6   (s=6)  表示1到12中，每2个数提供一个2
    // j=6:   6/2 = 3   (s=9)  表示1到12中，每4个数额外提供一个2
    // j=3:   3/2 = 1   (s=10) 表示1到12中，每8个数额外提供一个2
    // j=1:   1/2 = 0   结束循环
*/

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}