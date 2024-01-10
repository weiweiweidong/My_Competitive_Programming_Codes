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
    int N, H, X;
    cin >> N >> H >> X;

    for (int i = 1; i <= N; i++) {
        int P;
        cin >> P;
        if (H + P >= X) {
            cout << i << endl;
            return 0;
        }
    }
}