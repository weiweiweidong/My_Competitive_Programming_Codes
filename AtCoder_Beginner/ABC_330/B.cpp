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
    int N, L, R;
    cin >> N >> L >> R;
    while (N--) {
        int A;
        cin >> A;
        if (A < L)
            cout << L;
        else if (A > R)
            cout << R;
        else
            cout << A;

        if (N)
            cout << " ";
        else
            cout << endl;
    }
}