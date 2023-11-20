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
    int N;
    cin >> N;
    int res = 100;

    for (int i = 1; i <= 9; i++) {
        for (int j = 0; j <= 9; j++) {
            if (i * j <= 9) {
                int temp = i * 100 + j * 10 + i * j;
                if (temp >= N && abs(N - temp) <= abs(N - res))
                    res = temp;
            }
        }
    }

    cout << res << endl;
}