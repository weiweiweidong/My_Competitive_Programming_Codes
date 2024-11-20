// https://atcoder.jp/contests/abc173/tasks/abc173_a

#include <iostream>
using namespace std;

int N;

int main() {
    cin >> N;

    if (N % 1000)
        cout << (N / 1000 + 1) * 1000 - N << endl;
    else
        cout << "0" << endl;
}
