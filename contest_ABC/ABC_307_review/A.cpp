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
    int N ; cin >> N;
    vector<int> a( 7*N+1  , 0 );

    for( int i = 1 ; i <= 7*N ; i++ ) cin >> a[i];

    int res = 0;
    for( int i = 1 ; i <= 7*N ; i++ ){
        res += a[i];
        if( i % 7 == 0 || i == 7*N ){
            cout << res << " ";
            res = 0;
        }
    }
    cout << endl;
}