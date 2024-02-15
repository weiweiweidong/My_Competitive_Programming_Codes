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
    int N;
    cin >> N;
    int T = 0, A = 0;
    while (N--) {
        int t, a;
        cin >> t >> a;
        T += t;
        A += a;
    }

    if (T > A)
        cout << "Takahashi" << endl;
    else if (T < A)
        cout << "Aoki" << endl;
    else
        cout << "Draw" << endl;
}