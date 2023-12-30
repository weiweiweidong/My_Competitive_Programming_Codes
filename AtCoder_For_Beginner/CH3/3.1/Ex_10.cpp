// https://atcoder.jp/contests/abc157/tasks/abc157_a

#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;

    if (N % 2)
        cout << (N / 2 + 1) << endl;
    else
        cout << N / 2 << endl;
}
