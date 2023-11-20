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
    int X, Y;
    cin >> X >> Y;
    if (Y - X <= 2 && Y - X >= -3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}