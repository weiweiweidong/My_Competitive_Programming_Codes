// Problem: https://www.acwing.com/problem/content/200/

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int primes[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
int maxd;
int number;
int n;

void dfs(int u, int last, int p, int s) {
    if (s > maxd || s == maxd && p < number) {
        maxd = s;
        number = p;
    }

    if (u == 9)
        return;

    for (int i = 1; i <= last; i++) {
        if ((LL)p * primes[u] > n)
            break;
        p *= primes[u];
        dfs(u + 1, i, p, s * (i + 1));
    }
}

void solve() {
    cin >> n;
    dfs(0, 30, 1, 1);

    cout << number << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}