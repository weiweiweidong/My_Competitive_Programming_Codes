
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
    int N, S, M, L;
    cin >> N >> S >> M >> L;

    int res = 1e9;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            for (int k = 0; k < 10; k++) {
                int num = 6 * i + 8 * j + 12 * k;
                if (num >= N) {
                    res = min(res, S * i + M * j + L * k);
                }
            }
        }
    }

    cout << res << endl;
}