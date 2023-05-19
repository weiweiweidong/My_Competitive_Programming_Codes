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
    cin >> n;
    vector<int> a(n);
    for( int i = 0 ; i < n ; i++ ) cin >> a[i];

    for( int i = 1 ; i < a.size() ; i++ ){
        if( a[i-1] + 1 < a[i] ) a.insert(a.begin()+i , a[i-1]+1);
        if( a[i-1] - 1 > a[i] ) a.insert(a.begin()+i , a[i-1]-1);
    }

    for( auto x : a) cout << x << ' ';
    cout << endl;

    return 0;
}