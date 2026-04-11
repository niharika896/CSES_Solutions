#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vll vector<vector<ll>>
#define vii vector<vector<int>>
#define vi vector<int>
#define vl vector<ll>
#define imax INT_MAX
#define imin INT_MIN

// //
// You are given an integer n. On each step, you may subtract one of the digits from the number.
// How many steps are required to make the number equal to 0?
// Input
// The only input line has an integer n.
// Output
// Print one integer: the minimum number of steps.
// Constraints

// 1 \le n \le 10^6

// Example
// Input:
// 27

// Output:
// 5

// Explanation: An optimal solution is 27 \rightarrow 20 \rightarrow 18 \rightarrow 10 \rightarrow 9 \rightarrow 0.
// //
int dp(int num,vi& memo){
    if(num<0)return 1e9;
    if(num==0)return 0;
    if(memo[num]!=-1)return memo[num];
    int ways=1e9;
    int temp=num;
    while(temp>0){
        int digit = temp%10;
        if(digit!=0)
        ways = min(ways,1+dp(num-digit,memo));
        temp/=10;
    }
    return memo[num]=ways;
}

int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n;
cin>>n;
vi memo(n+1,-1);
// vi memo(n+1,1e9);
// memo[0]=0;
// for(int i=1;i<=n;i++){
//     int temp=i;
//     while(temp>=0){
//         int digit = temp%10;
//         if(digit!=0){
//             memo[i]=min(memo[i],memo[i-digit]+1);
//         }
//         temp/=10;
//     }
// }
// cout<<memo[n];
cout<<dp(n,memo);


return 0;
}