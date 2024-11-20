// https://atcoder.jp/contests/abc083/tasks/abc083_a

#include <iostream>
using namespace std;

int N, A, B;

// 计算各位数的和
int calc_sum_digit(int x) {
    int sum_digit = 0;
    while (x) {
        sum_digit += x % 10;
        x /= 10;
    }
    return sum_digit;
}

int main() {
    cin >> N >> A >> B;

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int digit_sum = calc_sum_digit(i);
        if (digit_sum >= A && digit_sum <= B)
            sum += i;
    }
    cout << sum << endl;
    return 0;
}