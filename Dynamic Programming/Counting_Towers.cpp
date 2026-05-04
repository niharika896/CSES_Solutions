#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int mod = 1e9+7;
const int MAX = 1e6+5;

int memo[MAX][2]; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memo[1][0] = 1;
    memo[1][1] = 1;
    
    for(int i = 2; i < MAX; i++){
        memo[i][1] = (4LL * memo[i-1][1] + memo[i-1][0]) % mod;
        memo[i][0] = (memo[i-1][1] + 2LL * memo[i-1][0]) % mod;
    }

    int n; 
    cin >> n;
    while(n--){
        int m;
        cin >> m;
        cout << (memo[m][0] + memo[m][1]) % mod << '\n';
    }

    return 0;
}