#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <math.h>
#include <string.h>

typedef long L;
typedef long long LL;
using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> S;
    for( int i = 0 ; i < n ; i++ ){
        int t;
        cin >> t;
        S.insert(t);
    }

    cout << S.size() << endl;
}