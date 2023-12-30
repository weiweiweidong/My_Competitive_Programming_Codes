// https://atcoder.jp/contests/abc137/tasks/abc137_a

#include <iostream>
using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    int C = -2e8;
    C = max(A + B, A - B);
    C = max(C, A * B);
    cout << C << endl;
}
