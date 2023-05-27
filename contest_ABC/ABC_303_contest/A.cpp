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

bool check( char a , char b ){
    if( a == b || (a == '1' && b == 'l') || (a == 'l' && b == '1') || (a == '0' && b == 'o') || (a == 'o' && b == '0')){
        return true;
    }
    else return false;
}

int main(){
    string a , b;
    int n;
    cin >> n;
    cin >> a >> b;

    int res = 0;
    for( int i = 0 ; i < n ; i++ ){
        if( check( a[i] , b[i] )) res++;
    }


    if( res == n ) cout << "Yes" << endl;
    else cout << "No" << endl;

}