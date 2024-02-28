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
    string N;
    cin >> N;

    int n = N.size();
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (N[i] <= N[i + 1])
            flag = false;
    }

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}