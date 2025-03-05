// https://atcoder.jp/contests/abc088/tasks/abc088_a

#include <iostream>
using namespace std;

int N, A;

int main() {
    cin >> N >> A;
    if (N % 500 <= A)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
