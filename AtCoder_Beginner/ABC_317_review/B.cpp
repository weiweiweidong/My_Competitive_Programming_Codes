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
    vector<int> A(N);
    int res = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        res -= A[i];
    }

    int mi = *min_element(A.begin(), A.end());
    int ma = *max_element(A.begin(), A.end());
    for (int i = mi; i <= ma; i++) {
        res += i;
    }

    cout << res << endl;
}