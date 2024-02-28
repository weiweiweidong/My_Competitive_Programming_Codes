// https://atcoder.jp/contests/abc093/tasks/abc093_b

#include <iostream>
#include <vector>
using namespace std;

int A, B, K;

int main() {
    cin >> A >> B >> K;
    if (B - A + 1 > K * 2) {
        for (int i = A; i < A + K; i++)
            cout << i << endl;
        for (int i = B - K + 1; i <= B; i++)
            cout << i << endl;
    } else {
        for (int i = A; i <= B; i++)
            cout << i << endl;
    }
}
