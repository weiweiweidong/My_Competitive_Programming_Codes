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

bool check( string s ){
    string t = s;
    reverse( t.begin() , t.end() );
    if( t == s ) return true;
    else return false;
}

int main(){
    int N; cin >> N;
    vector<string> S(N , "");
    for( int i = 0 ; i < N ; i++ ) cin >> S[i];

    for( int i = 0 ; i < N-1 ; i++){
        for( int j = i+1 ; j < N ; j++ ){
            string t = S[i] + S[j];
            if( check(t) ){
                cout << "Yes" << endl;
                return 0;
            }
            t = S[j] + S[i];
            if( check(t) ){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}