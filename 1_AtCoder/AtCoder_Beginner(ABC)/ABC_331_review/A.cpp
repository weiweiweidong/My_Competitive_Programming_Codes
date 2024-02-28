
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

int main() {
    int M, D;
    cin >> M >> D;
    int y, m, d;
    cin >> y >> m >> d;

    // 加一天
    d++;
    // 如果day超了。month++，day置1
    if (d > D) {
        d = 1;
        m++;
    }
    // 如果month超了。year++，month置1
    if (m > M) {
        m = 1;
        y++;
    }

    cout << y << " " << m << " " << d << endl;
}