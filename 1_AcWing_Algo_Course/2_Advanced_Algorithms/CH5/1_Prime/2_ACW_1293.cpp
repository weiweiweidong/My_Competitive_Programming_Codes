// Problem:

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;
int primes[N], cnt;
bool st[N];
int n;

// 筛质数（线性筛法）
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

void solve() {
    cin >> n;
    get_primes(n + 1);

    // 输出染多少种颜色
    if (n <= 2)
        cout << "1" << endl;
    else
        cout << "2" << endl;

    // 输出每个数字对应的颜色
    for (int i = 2; i <= n + 1; i++) {
        // 如果是质数，输出 1
        if (!st[i])
            cout << "1 ";
        // 如果不是质数，输出 2
        else
            cout << "2 ";
    }
    cout << endl;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}