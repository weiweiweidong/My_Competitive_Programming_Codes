#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <math.h>
#include <string.h>

typedef long l;
typedef long long ll;
using namespace std;


int main(){
    int n , k;
    cin >> n >> k;
    vector<int> A(n , 0);
    vector<int> B(n , 0);
    for( int i = 0 ; i < n ; i++ ) cin >> A[i];
    for( int i = 0 ; i < n ; i++ ) cin >> B[i];

    int res = 0;
    for( int i = 0 ; i < n ; i++ ){
        res += abs( A[i] - B[i] );
    }

    if( res > k || (k-res)%2 != 0 ) cout << "No" << endl;
    else cout << "Yes" << endl;


    return 0;
        
}