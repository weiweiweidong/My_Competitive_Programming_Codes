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
    string S;
    cin >> S;
    int n = S.size();
    bool flag = true;

    if (S[0] >= 'A' && S[0] <= 'Z') {
        for (int i = 1; i < n; i++) {
            if (S[i] >= 'A' && S[i] <= 'Z')
                flag = false;
        }
    } else
        flag = false;

    if (flag)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}