// Problem: https://www.acwing.com/problem/content/869/
// 分解质因数
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, a;

void divide(int x) {
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0) {
            int cnt = 0;
            while (x % i == 0)
                x /= i, cnt++;
            cout << i << " " << cnt << endl;
        }
    }
    if (x > 1)
        cout << x << " " << 1 << endl;
    cout << endl;
}

void solve() {
    cin >> n;
    while (n--) {
        cin >> a;
        divide(a);
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}