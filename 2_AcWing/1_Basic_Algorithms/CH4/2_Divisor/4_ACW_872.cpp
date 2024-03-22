// Problem: https://www.acwing.com/problem/content/874/
// GCD算法求最大公约数
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a, b;

int GCD(int a, int b) {
    if (b == 0)
        return a;
    return GCD(b, a % b);

    // 或者可以直接写成下面的形式
    // return b ? gcd( b , a % b ) : a;
}

void solve() {
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cout << GCD(a, b) << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}