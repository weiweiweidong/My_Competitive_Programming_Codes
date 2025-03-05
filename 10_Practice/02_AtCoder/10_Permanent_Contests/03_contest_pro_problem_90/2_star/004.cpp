#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <math.h>

typedef long l;
typedef long long ll;
using namespace std;


int main(){
    int H, W;
    cin >> H >> W;
    vector<vector<int>> g(H , vector<int>(W , 0));
    vector<int> col(W, 0) , row(H,0);
    for( int i = 0 ; i < H ; i++ ){
        for( int j = 0 ; j < W ; j++ ){
            cin >> g[i][j];
            col[j] += g[i][j];
            row[i] += g[i][j];
        }
    }

    vector<vector<int>> res(H , vector<int>(W , 0));
    for( int i = 0 ; i < H ; i++ ){
        for( int j = 0 ; j < W ; j++ ){
            res[i][j] = row[i] + col[j] - g[i][j];
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
        
}