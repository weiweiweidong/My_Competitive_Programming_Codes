// https://atcoder.jp/contests/abc165/tasks/abc165_b

#include <iostream>
using namespace std;

long long X;

int main() {
    cin >> X;
    int i = 0;
    long long deposit = 100;
    while (deposit < X) {
        deposit += (deposit / 100);
        i++;
    }
    cout << i << endl;
    return 0;
}
