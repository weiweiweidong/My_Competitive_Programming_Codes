// Problem:

// a和b都是10^18次方的长度，直接相乘肯定会爆

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;

// 快速和
LL qadd(LL a, LL b, LL p) {
    LL res = 0;
    while (b) {
        if (b & 1)
            res = (res + a) % p;
        a = (a + a) % p;
        b >>= 1;
    }
    return res;
}

void solve() {
    LL a, b, p;
    scanf("%lld%lld%lld", &a, &b, &p);
    printf("%lld\n", qadd(a, b, p));
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}