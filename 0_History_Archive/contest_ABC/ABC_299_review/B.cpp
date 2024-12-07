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
    int N, T;
    cin >> N >> T;
    vector<int> C(N), R(N);
    unordered_map<int, int> times;
    for (int i = 0; i < N; i++) {
        cin >> C[i];
        times[C[i]]++;
    }
    for (int i = 0; i < N; i++)
        cin >> R[i];

    int t = 0;
    if (times.count(T)) {
        t = T;
    } else {
        t = C[0];
    }

    int res = -1;
    int pos = 0;
    for (int i = 0; i < N; i++) {
        if (C[i] == t) {
            if (res == -1) {
                pos = i;
                res = 1;
            } else {
                if (R[pos] < R[i])
                    pos = i;
            }
        }
    }

    cout << pos + 1 << endl;
}