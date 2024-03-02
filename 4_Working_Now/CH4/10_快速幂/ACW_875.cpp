#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

int apow(int a, int k, int p) {
    int res = 1;
    while (k) {
        if (k & 1)
            res = (LL)res * a % p;
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}

int n, a, k, p;
int main() {
    cin >> n;
    while (n--) {
        cin >> a >> k >> p;
        cout << apow(a, k, p) << endl;
    }
}