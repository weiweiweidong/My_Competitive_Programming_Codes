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
    int N, Q;
    cin >> N >> Q;
    vector<unsigned long long> car(N);
    for (int i = 0; i < N; i++)
        cin >> car[i];
    sort(car.begin(), car.end());

    vector<unsigned long long> sum(N + 1, 0);
    for (int i = 1; i <= N; i++)
        sum[i] = sum[i - 1] + car[i - 1];

    while (Q--) {
        LL X;
        cin >> X;
        int pos = upper_bound(sum.begin(), sum.end(), X) - sum.begin();
        cout << pos - 1 << endl;
    }
}