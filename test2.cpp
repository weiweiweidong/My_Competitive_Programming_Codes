#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    std::cin >> a >> b;

    i64 C;
    std::cin >> C;

    // 计算C里面有多少1
    int c = __builtin_popcountll(C);
    // 不可能有解
    if (a + b < c || (a + b - c) % 2 == 1) {
        std::cout << -1 << "\n";
        return 0;
    }

    // 计算出重叠部分有多少位
    int ex = (a + b - c) / 2;
    // 不可能有解
    if (ex + c > 60) {
        std::cout << -1 << "\n";
        return 0;
    }

    // 减去重叠部分
    a -= ex;
    b -= ex;
    // 不可能有解
    if (a < 0 || b < 0) {
        std::cout << -1 << "\n";
        return 0;
    }

    i64 X = 0, Y = 0;
    for (int i = 0; i < 60; i++) {
        // 若C的第i位为1
        if (C >> i & 1) {
            // 如果a还有剩余
            if (a) {
                // 把X的第i位变为1
                X |= 1LL << i;
                a--;
            } else {
                // 把Y的第i位变为1
                Y |= 1LL << i;
                b--;
            }
        }
        // 如果C的第i位为0，优先把重合的ex部分放进去
        else if (ex) {
            X |= 1LL << i;
            Y |= 1LL << i;
            ex--;
        }
    }
    // 输出X和Y
    std::cout << X << " " << Y << "\n";

    return 0;
}