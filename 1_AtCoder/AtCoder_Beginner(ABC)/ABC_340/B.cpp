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
    int Q;
    cin >> Q;
    vector<int> A;
    while (Q--) {
        int q;
        cin >> q;
        if (q == 1) {
            int x;
            cin >> x;
            A.push_back(x);
        } else if (q == 2) {
            int k;
            cin >> k;
            int n = A.size();
            cout << A[n - k] << endl;
        }
    }
}