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
    int N, M, P;
    cin >> N >> M >> P;

    if (N < M)
        cout << "0" << endl;
    else {
        cout << (N - M) / P + 1 << endl;
    }
}