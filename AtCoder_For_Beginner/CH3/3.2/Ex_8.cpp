// https://atcoder.jp/contests/abc158/tasks/abc158_c

#include <iostream>
#include <vector>
using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    for (int i = 1; i <= 1255; i++) {
        if ((int)(i * 0.08) == A && (int)(i * 0.1) == B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}
