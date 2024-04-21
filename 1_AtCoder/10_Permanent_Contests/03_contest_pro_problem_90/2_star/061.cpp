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
    int N;
    cin >> N;
    vector<int> c;
    for( int i = 0 ; i < N ; i++ ){
        int t , x;
        cin >> t >> x;
        if( t == 1 ) c.insert( c.begin() , x);
        else if( t == 2 ) c.push_back(x);
        else if( t == 3 ) cout << c[x-1] << endl;
    }

    return 0;
}