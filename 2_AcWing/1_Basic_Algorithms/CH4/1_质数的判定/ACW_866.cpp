#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

bool is_prime(int x) {
    if (x <= 1)
        return false;
    for (int i = 2; i <= x / i; i++) {
        if (x % i == 0)
            return false;
    }
    return true;
}

int n, x;
int main() {
    cin >> n;
    while (n--) {
        cin >> x;
        if (is_prime(x))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}