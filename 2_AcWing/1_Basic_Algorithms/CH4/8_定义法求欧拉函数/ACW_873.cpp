#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = 1e9 + 7;
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

int main() {
    cin >> n;
    while (n--) {
        cin >> x;
        cout << phi(x) << endl;
    }
}