// 快速筛出 2～n 之间的质数

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int primes[N], cnt;
bool st[N];

// 方法1:这是最慢的筛法
void get_primes1(int x) {
    for (int i = 2; i <= x; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
        }
        for (int j = i + i; j <= x; j += i)
            st[j] = true;
    }
}

// 方法2:埃氏筛法
void get_primes2(int x) {
    for (int i = 2; i <= x; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            for (int j = i + i; j <= x; j += i)
                st[j] = true;
        }
    }
}

// 方法3:线性筛法（最快）
void get_primes3(int x) {
    vector<int> primes;
    for (int i = 2; i <= x; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int n;
int main() {
    cin >> n;
    get_primes3(n);
    cout << cnt << endl;
}