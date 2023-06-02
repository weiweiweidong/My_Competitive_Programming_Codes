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
    int n , y;
    cin >> n >> y;

    for( int i = 0 ; i <= n ; i++ ){
        for( int j = 0 ; j <= n-i ; j++ ){
            int k = n-i-j;
            int t = 10000*i + 5000*j + 1000*k;
            if( t == y ){
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1 -1" << endl;
}