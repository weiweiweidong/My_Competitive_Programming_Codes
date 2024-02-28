// https://atcoder.jp/contests/abc220/tasks/abc220_b

#include <iostream>
#include <vector>
using namespace std;

int K;
string A, B;

// 将k进制的x转换为10进制的数字
long long k_to_10(string x, int k) {
    long long res = 0;
    for (auto c : x) {
        res = res * k + (c - '0');
    }
    return res;
}

int main() {
    cin >> K >> A >> B;
    cout << k_to_10(A, K) * k_to_10(B, K) << endl;
}
