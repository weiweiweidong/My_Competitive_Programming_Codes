#include <math.h>
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long L;
typedef long long LL;
using namespace std;

int main() {
    LL a, b;
    cin >> a >> b;
    LL res = 0;
    while (a != b) {
        // 保证a大
        if (b > a)
            swap(a, b);
        // 能整除
        if (a % b == 0) {
            res += a / b - 1;
            a = b;
        }
        // 不能整除
        else {
            res += a / b;
            a = a % b;
        }
    }

    cout << res << endl;
}