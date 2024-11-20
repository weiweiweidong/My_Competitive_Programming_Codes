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

string long_to_base5(LL N) {
    if (N == 0)
        return "0";
    string res;
    while (N > 0) {
        res = char(N % 5 * 2 + '0') + res;
        N /= 5;
    }

    return res;
}

int main() {
    LL N;
    cin >> N;
    cout << long_to_base5(N - 1) << endl;
}