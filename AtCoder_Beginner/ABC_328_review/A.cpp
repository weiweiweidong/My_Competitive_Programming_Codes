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
    int N, X;
    cin >> N >> X;

    int res = 0;
    while (N--) {
        int x;
        cin >> x;
        if (x <= X)
            res += x;
    }
    cout << res << endl;
}