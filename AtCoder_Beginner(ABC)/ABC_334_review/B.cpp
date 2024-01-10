#include <math.h>
#include <string.h>
#include <algorithm>
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
    long long A, M, L, R;
    cin >> A >> M >> L >> R;

    if (L > A) {
        cout << (R - A) / M - (L - 1 - A) / M << '\n';
    } else if (R < A) {
        cout << (A - L) / M - (A - 1 - R) / M << '\n';
    } else {
        cout << (R - A) / M + (A - L) / M + 1 << '\n';
    }

    return 0;
}