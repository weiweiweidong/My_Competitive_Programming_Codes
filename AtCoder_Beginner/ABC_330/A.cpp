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
    int N, L;
    cin >> N >> L;
    int res = 0;
    while (N--) {
        int A;
        cin >> A;
        res += (A >= L);
    }
    cout << res << endl;
}