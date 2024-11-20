#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int N = 100010;

int n, F;
double a[N], s[N];

bool check(double avg) {
    // 预处理前缀和
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i] - avg;

    double mins = 0;
    // 枚举右端点
    for (int k = F; k <= n; k++) {
        mins = min(mins, s[k - F]);  // 找到前面的最优极小值
        if (s[k] - mins >= 0)        // 说明总和可以大于 avg
            return true;
    }

    return false;
}

int main() {
    scanf("%d%d", &n, &F);

    double l = 0, r = 0;
    // 读入数据，并获取牛的最大值
    for (int i = 1; i <= n; i++) {
        scanf("%lf", &a[i]);
        r = max(r, a[i]);
    }

    // 牛的数量在 0～2000 之间二分查找

    // 二分
    while (r - l > 1e-5) {
        double mid = (l + r) / 2;
        if (check(mid))  // 若成功，说明真实的平均数比 mid 大
            l = mid;
        else  // 若失败，说明真实的平均数比 mid 小
            r = mid;
    }

    printf("%d\n", (int)(r * 1000));

    return 0;
}
