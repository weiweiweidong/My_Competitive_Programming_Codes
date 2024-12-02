// Problem: https://www.acwing.com/problem/content/222/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e7 + 10;
int primes[N], cnt;
bool st[N];
int phi[N];
LL s[N];

void get_eulers(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }

        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }

    // 计算欧拉函数的前缀和
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + phi[i];
}

void solve() {
    int n;
    cin >> n;

    // 预处理出所有的欧拉函数值
    get_eulers(n);

    // 遍历每个质数
    LL res = 0;
    for (int i = 0; i < cnt; i++) {
        int p = primes[i];
        res += s[n / p] * 2 + 1;
    }

    cout << res << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}