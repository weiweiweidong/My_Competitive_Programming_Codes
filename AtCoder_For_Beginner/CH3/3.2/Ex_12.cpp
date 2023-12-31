// https://atcoder.jp/contests/typical90/tasks/typical90_bo

#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

int K;
string N;

// 将k进制的x转换为10进制的数字
LL base8_to_long(string x) {
    LL res = 0;
    for (auto c : x) {
        res = res * 8 + (c - '0');
    }
    return res;
}

//  将10进制转换为9进制
string long_to_base9(LL x) {
    if (x == 0)
        return "0";
    string res;
    while (x) {
        res = char(x % 9 + '0') + res;
        x /= 9;
    }
    return res;
}

int main() {
    cin >> N >> K;

    for (int i = 1; i <= K; i++) {
        N = long_to_base9(base8_to_long(N));
        for (auto& c : N) {
            if (c == '8')
                c = '5';
        }
    }
    cout << N << endl;
}
