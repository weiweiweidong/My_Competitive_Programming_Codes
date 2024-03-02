#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n;
int primes[N], cnt;
int phi[N];
bool st[N];

int get_eulers_sum(int x) {
    phi[1] = 1;
    for (int i = 2; i <= x; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            // 如果i是质数，说明前面的i-1个数都与i互质，欧拉数就为i-1
            phi[i] = i - 1;
        }

        // 开始遍历质数
        for (int j = 0; primes[j] <= x / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                phi[primes[j] * i] = phi[i] * primes[j];
                break;
            }
            phi[primes[j] * i] = phi[i] * (primes[j] - 1);
        }
    }
    LL res = 0;
    for (int i = 1; i <= x; i++)
        res += phi[i];
    return res;
}

// 注意：本题目是要对1～n之间的每一个数都求欧拉函数，所以时间复杂度非常高
int main() {
    cin >> n;
    cout << get_eulers_sum(n) << endl;
}
