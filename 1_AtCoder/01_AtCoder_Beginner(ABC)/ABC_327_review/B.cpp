#include <math.h>
#include <string.h>
#include <algorithm>
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

// 注意：16^16 约等于 18e18，就已经超过了题目的限制
int main() {
    LL B;
    cin >> B;
    for (int i = 1; i < 16; i++) {
        LL res = 1;
        for (int j = 1; j <= i; j++)
            res *= i;
        if (res == B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}