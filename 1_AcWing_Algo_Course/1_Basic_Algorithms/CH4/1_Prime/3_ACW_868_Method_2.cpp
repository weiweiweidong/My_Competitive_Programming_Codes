// Problem: https://www.acwing.com/problem/content/870/
// 筛选质数：线性筛法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e6 + 10;
int n;
int cnt;
bool st[N];
vector<int> primes;

void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes.push_back(i);
        for (int j = 0; primes[j] <= n / i; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve() {
    cin >> n;
    get_primes(n);
    cout << primes.size() << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}