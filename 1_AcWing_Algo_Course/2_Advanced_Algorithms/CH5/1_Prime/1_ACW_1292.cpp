// Problem: https://www.acwing.com/problem/content/1294/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1000010;
int primes[N], cnt;
bool st[N];

// 质数线性筛法
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = true;  // 不是质数的都会被标记为 true
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve() {
    // 预处理出来 100 万以内的所有质数
    get_primes(N - 1);

    int n;
    while (cin >> n, n) {
        for (int i = 1;; i++) {
            int a = primes[i];
            int b = n - a;
            if (!st[b]) {
                printf("%d = %d + %d\n", n, a, b);
                break;
            }
        }
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}