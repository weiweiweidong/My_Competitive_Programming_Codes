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

const int DIGIT_NUM = 12;

int main() {
    int n;
    cin >> n;

    LL A[DIGIT_NUM];
    A[0] = 1;
    for (int i = 1; i < DIGIT_NUM; i++)
        A[i] = A[i - 1] * 10 + 1;

    vector<LL> repunits;
    for (int i = 0; i < DIGIT_NUM; i++) {
        for (int j = i; j < DIGIT_NUM; j++) {
            for (int k = j; k < DIGIT_NUM; k++) {
                repunits.push_back(A[i] + A[j] + A[k]);
            }
        }
    }
    sort(repunits.begin(), repunits.end());

    cout << repunits[n - 1] << endl;
}