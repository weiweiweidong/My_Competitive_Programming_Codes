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
    int K, G, M;
    cin >> K >> G >> M;

    int g = 0, m = 0;
    for (int i = 1; i <= K; i++) {
        if (g == G)
            g = 0;
        else if (m == 0)
            m = M;
        else {
            if (G - g >= m) {
                g += m;
                m = 0;
            } else {
                m -= (G - g);
                g = G;
            }
        }
    }
    cout << g << " " << m << endl;
}