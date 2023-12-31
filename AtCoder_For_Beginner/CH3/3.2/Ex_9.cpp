// https://atcoder.jp/contests/abc068/tasks/abc068_b

#include <iostream>
#include <vector>
using namespace std;

int N;

int main() {
    cin >> N;

    int t = 1;
    while (t <= N) {
        t *= 2;
    }
    cout << t / 2 << endl;
}
