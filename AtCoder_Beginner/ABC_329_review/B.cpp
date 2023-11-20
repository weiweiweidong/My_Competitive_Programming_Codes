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

#include <type_traits>

using namespace std;
int main() {
    int N;
    cin >> N;
    int a = 0, b = 0;
    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp > a) {
            b = a;
            a = temp;
        } else if (temp > b && temp < a) {
            b = temp;
        }
    }
    cout << b << endl;
}