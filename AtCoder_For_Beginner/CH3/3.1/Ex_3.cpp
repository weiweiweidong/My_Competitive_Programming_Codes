// https://atcoder.jp/contests/abc118/tasks/abc118_a

#include <iostream>
using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    if (B % A)
        cout << B - A << endl;
    else
        cout << A + B << endl;
}
