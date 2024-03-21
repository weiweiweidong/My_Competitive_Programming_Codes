// Problem: https://www.acwing.com/problem/content/870/
// 筛选质数：埃氏筛法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n;
int primes[N], cnt;
bool st[N];

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) {
            primes[cnt++] = i;
            for (int j = i + i; j <= n; j += i)
                st[j] = true;
        }
    }
}

void solve() {
    cin >> n;
    get_primes(n);
    cout << cnt << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}