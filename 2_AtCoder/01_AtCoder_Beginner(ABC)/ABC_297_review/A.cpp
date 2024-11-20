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
    int N, D;
    cin >> N >> D;
    vector<int> T(N);
    for (int& x : T)
        cin >> x;

    bool flag = false;
    for (int i = 0; i < N - 1; i++) {
        if (T[i + 1] - T[i] <= D) {
            cout << T[i + 1] << endl;
            flag = true;
            break;
        }
    }
    if (!flag)
        cout << -1 << endl;
}