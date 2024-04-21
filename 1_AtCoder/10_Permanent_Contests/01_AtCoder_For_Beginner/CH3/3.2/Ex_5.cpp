// https://atcoder.jp/contests/abc164/tasks/abc164_b

#include <iostream>
using namespace std;

int A, B, C, D;

int main() {
    cin >> A >> B >> C >> D;

    int X = (A + D - 1) / D;  // 高桥被攻击的次数
    int Y = (C + B - 1) / B;  // 青木被攻击的次数
    // 当X=Y的情况下，由于青木先被攻击，所以青木先挂，还是高桥赢
    if (X >= Y)
        cout << "Yes" << endl;
    else if (X < Y)
        cout << "No" << endl;
}
