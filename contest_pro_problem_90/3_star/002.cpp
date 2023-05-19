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

char path[22];
int N;

void dfs( int u , int bl , int br ){
    if( u == N ){
        for( int i = 0 ; i < N ; i++ ) cout << path[i];
        cout << endl;
        return;
    }

    if( bl < N/2 ){
        path[u] = '(';
        dfs( u+1 , bl+1 , br);
    }
    if( br < bl ){
        path[u] = ')';
        dfs( u+1 , bl , br+1 );
    }
}

int main(){
    cin >> N;
    if( N == 0 || N % 2 ) return 0;

    dfs(0 , 0 , 0 );
    
    return 0;
        
}