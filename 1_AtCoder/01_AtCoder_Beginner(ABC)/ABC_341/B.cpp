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
    int n;
    cin >> n;
    vector<LL> A(n);
    for (LL& x : A)
        cin >> x;
    vector<LL> S(n - 1), T(n - 1);
    for (int i = 0; i < n - 1; i++)
        cin >> S[i] >> T[i];

    for (int i = 0; i < n - 1; i++) {
        A[i + 1] += (A[i] / S[i]) * T[i];
    }

    cout << A[n - 1] << endl;
}