// Problem: https://www.acwing.com/problem/content/876/
// 线性筛法求欧拉函数
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n;
int primes[N], cnt;
int phi[N];
bool st[N];

LL get_eulers(int x) {
    phi[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            // 如果当i是质数的时候，欧拉函数phi[i] 为 i-1
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }

    LL res = 0;
    for (int i = 1; i <= n; i++)
        res += phi[i];
    return res;
}

void solve() {
    cin >> n;
    cout << get_eulers(n) << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}