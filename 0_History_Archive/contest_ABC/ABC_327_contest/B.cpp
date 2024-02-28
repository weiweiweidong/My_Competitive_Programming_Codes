#include <math.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef long L;
typedef long long LL;
using namespace std;

int main() {
    string B;
    cin >> B;
    for (int i = 1; i < 17; i++) {
        unsigned long long res = i;
        for (int j = 1; j < i; j++) {
            res *= i;
        }
        string s = to_string(res);
        if (s == B) {
            cout << i << endl;
            return 0;
        }
    }
    cout << "-1" << endl;
}