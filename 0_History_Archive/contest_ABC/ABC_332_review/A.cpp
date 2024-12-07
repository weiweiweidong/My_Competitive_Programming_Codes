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
    LL N, S, K;
    cin >> N >> S >> K;

    LL res = 0;
    for (int i = 1; i <= N; i++) {
        LL P, Q;
        cin >> P >> Q;
        res += (P * Q);
    }

    if (res >= S)
        cout << res << endl;
    else
        cout << res + K << endl;
}