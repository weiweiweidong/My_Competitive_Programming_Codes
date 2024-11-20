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

const int N = 1e5+10;
int stu1[N] , stu2[N];
int p1[N] , p2[N];


int main(){
    int N;
    cin >> N;
    memset( stu1 , 0 , sizeof stu1);
    memset( stu2 , 0 , sizeof stu2);
    memset( p1 , 0 , sizeof p1);
    memset( stu1 , 0 , sizeof stu1);

    for( int i = 1 ; i <= N ; i++ ){
        int cl , sc;
        cin >> cl >> sc;
        if( cl == 1 ) stu1[i] = sc;
        else stu2[i] = sc;
    }

    for(int i = 0 ; i <= N ; i++ ){
        p1[i] = p1[i-1] + stu1[i];
        p2[i] = p2[i-1] + stu2[i];
    }

    int Q;
    cin >> Q;
    for( int i = 0 ; i < Q ; i++ ){
        int a, b;
        cin >> a >> b;
        cout << p1[b]-p1[a-1] << " " << p2[b]-p2[a-1] << endl;
    }

    return 0;
        
}