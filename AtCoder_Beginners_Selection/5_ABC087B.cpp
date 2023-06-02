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
    int a , b , c , x;
    cin >> a >> b >> c >> x;

    int res = 0;
    for( int i = 0 ; i <= a ; i++ ){
        for( int j = 0 ; j <= b ; j++ ){
            for( int k = 0 ; k <= c ; k++ ){
                int t = 500*i + 100*j + 50*k;
                if( t == x ) res++;
            }
        }
    }

    cout << res << endl;
}