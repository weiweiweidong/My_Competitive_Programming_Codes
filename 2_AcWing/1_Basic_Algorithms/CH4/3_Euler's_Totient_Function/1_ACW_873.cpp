// Problem: https://www.acwing.com/problem/content/875/
// 定义法求欧拉函数
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, x;

int phi(int x) {
    int res = x;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}

void solve() {
    cin >> n;
    while (n--) {
        cin >> x;
        cout << phi(x) << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}