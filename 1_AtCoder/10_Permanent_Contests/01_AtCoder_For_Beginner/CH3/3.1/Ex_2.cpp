// https://atcoder.jp/contests/abc127/tasks/abc127_a

#include <iostream>
using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    if (A >= 13)
        cout << B << endl;
    else if (A >= 6)
        cout << B / 2 << endl;
    else
        cout << 0 << endl;
}
