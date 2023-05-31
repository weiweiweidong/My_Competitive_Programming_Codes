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
    int p[n];
    int res = 1e9;
    for( int i = 0 ; i < n ; i++ ){
        cin >> p[i];
        res = min( res, p[i] & -p[i]);
    }

    cout << __builtin_ctz(res) << endl;
    // int k = 0;
    // for( int i = 0 ; i < 32 ; i++ ){
    //     if( res & 1 ) break;
    //     else{
    //         k++;
    //         res = res >> 1;
    //     }
    // }
    // cout << k << endl;
}