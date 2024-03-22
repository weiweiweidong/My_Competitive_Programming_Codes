// Problem: https://www.acwing.com/problem/content/871/
// 求n的所有约数
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int n, x;

vector<int> get_divisors(int n) {
    vector<int> res;
    for (int i = 1; i <= n / i; i++) {
        if (n % i == 0) {
            res.push_back(i);
            // 判断一下边界情况（排除 i平方等于n 的情况）
            if (i != n / i)
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

void solve() {
    int n;
    cin >> n;
    while (n--) {
        cin >> x;
        vector<int> res = get_divisors(x);
        for (int t : res)
            cout << t << " ";
        cout << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
