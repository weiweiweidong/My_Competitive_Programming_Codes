// https://atcoder.jp/contests/abc176/tasks/abc176_a

#include <iostream>
using namespace std;

int N, X, T;

int main() {
    cin >> N >> X >> T;

    if (N % X)
        cout << (N / X + 1) * T << endl;
    else
        cout << N / X * T << endl;
}
