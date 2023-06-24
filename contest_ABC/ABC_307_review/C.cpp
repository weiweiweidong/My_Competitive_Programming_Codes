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
    int h , w;
    vector<set<pair<int,int>>> V(3);

    for( int x = 0 ; x < 3 ; x++ ){
        cin >> h >> w;
        for( int i = 0 ; i < h ; i++ ){
            for( int j = 0 ; j < w ; j++ ){
                char ch; cin >> ch;
                if( ch == '#' ) V[x].emplace(i,j);
            }
        }
    }

    for( int i = -10 ; i <= 10 ; i++ ){
        for( int j = -10 ; j <= 10 ; j++ ){
            for( int k = -10 ; k <= 10 ; k++ ){
                for( int l = -10 ; l <= 10 ; l++ ){
                    set<pair<int,int>> cup;
                    for( auto &&s : V[0] ){
                        cup.emplace( s.first+i , s.second+j);
                    }
                    for( auto &&s : V[1] ){
                        cup.emplace( s.first+k , s.second+l);
                    }
                    if( cup == V[2] ){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "No" << endl;
    return 0;
}