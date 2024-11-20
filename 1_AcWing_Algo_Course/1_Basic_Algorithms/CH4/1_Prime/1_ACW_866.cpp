// Problem: https://www.acwing.com/problem/content/868/
// 质数判定
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, x;

bool is_prime(int n) {
    if (n < 2)
        return false;
    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void solve() {
    cin >> n;
    while (n--) {
        cin >> x;
        if (is_prime(x))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}