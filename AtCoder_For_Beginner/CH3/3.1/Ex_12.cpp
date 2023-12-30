// https://atcoder.jp/contests/typical90/tasks/typical90_ag

#include <iostream>
using namespace std;

int H, W;
// 这道题有一种日语理解的感觉：
// 题目中只说了“满足下列条件为不合适情况”：
// 2*2 格子中，点灯LED在2个以上
// 潜台词是，如果没有 2*2 的方格，怎么点灯都无所谓。
int main() {
    cin >> H >> W;

    if (H == 1 || W == 1)
        cout << H * W << endl;
    else
        cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;
}
