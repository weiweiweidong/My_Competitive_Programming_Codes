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

typedef long L;
typedef long long LL;
using namespace std;


int main(){
    int n , p , q;
    cin >> n >> p >> q;
    vector<LL> A(n);
    for( int i = 0 ; i <n ; i++ ) cin >> A[i];

    int res = 0;
    for( int i = 0 ; i < n-4 ; i++ ){
        LL t = 0;
        for( int j = i+1 ; j < n-3 ; j++ ){
            for( int k = j+1 ; k < n-2 ; k++ ){
                for( int l = k+1 ; l < n-1 ; l++ ){
                    for( int m = l+1 ; m < n ; m++ ){
                        t = 1LL * A[i] *A[j]%p*A[k]%p*A[l]%p*A[m]%p;
                        if( t == q ) res ++;
                    }
                }
            }
        }
    }
    cout << res<< endl;

    return 0;
}