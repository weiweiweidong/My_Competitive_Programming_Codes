#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

int main() {
    int a, b;
    cin >> a >> b;

    for (int i = 0; i <= 9; i++) {
        if (i != a + b) {
            cout << i << endl;
            return 0;
        }
    }
}