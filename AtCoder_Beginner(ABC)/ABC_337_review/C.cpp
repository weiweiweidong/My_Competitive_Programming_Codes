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
    unordered_map<int, int> h;
    for (int i = 1; i <= N; i++) {
        int A;
        cin >> A;
        h[A] = i;
    }

    int t = -1;
    for (int i = 1; i <= N; i++) {
        cout << h[t] << (i == N ? "" : " ");
        t = h[t];
    }
    cout << endl;
}