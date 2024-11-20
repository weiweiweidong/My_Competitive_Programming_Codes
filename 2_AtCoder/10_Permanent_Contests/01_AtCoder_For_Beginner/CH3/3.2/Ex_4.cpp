// https://atcoder.jp/contests/abc200/tasks/abc200_b

#include <iostream>
using namespace std;

long long N, K;

int main() {
    cin >> N >> K;
    int i = 0;
    while (K--) {
        if (N % 200)
            N = N * 1000 + 200;
        else
            N /= 200;
    }
    cout << N << endl;
}
