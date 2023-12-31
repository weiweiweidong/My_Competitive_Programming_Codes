// https://atcoder.jp/contests/abc165/tasks/abc165_a

#include <iostream>
using namespace std;

int K, A, B;

int main() {
    cin >> K >> A >> B;
    for (int i = A; i <= B; i++) {
        if (i % K == 0) {
            cout << "OK" << endl;
            return 0;
        }
    }
    cout << "NG" << endl;
    return 0;
}