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
    unordered_set<string> S;
    int n;
    cin >> n;
    for( int i = 0 ; i < n ; i++ ){
        string t;
        cin >> t;
        if( !S.count(t) ){
            S.insert(t);
            cout << i+1 << endl;
        }
    }


    return 0;
        
}