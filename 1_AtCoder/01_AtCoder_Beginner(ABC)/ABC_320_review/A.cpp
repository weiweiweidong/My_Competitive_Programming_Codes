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
    int A, B;
    cin >> A >> B;
    LL res = 0;

    LL a = 1;
    for (int i = 1; i <= B; i++) {
        a *= A;
    }

    LL b = 1;
    for (int i = 1; i <= A; i++) {
        b *= B;
    }

    cout << a + b << endl;
}
