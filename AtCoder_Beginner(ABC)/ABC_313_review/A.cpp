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

int n, x, m, k;

int main() {
    cin >> n;
    map<int, int> h;
    k = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        k = max(k, x);
        h[x]++;
        if (i == 1)
            m = x;
    }
    if (m == k && h[m] > 1)
        cout << "1" << endl;
    else if (m == k)
        cout << "0" << endl;
    else
        cout << k - m + 1 << endl;
}