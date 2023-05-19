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
    int n;
    string s;
    cin >> n >> s;

    int a = 0 , t = 0;
    for( int i = 0 ; i < n ; i++ ){
        if( s[i] == 'T' ) t++;
        else a++;
    }
    if( t > a ) cout << 'T' << endl;
    else if( t < a ) cout << 'A' << endl;
    else cout << char( 'T' + 'A' - s.back() ) << endl;

    return 0;
}