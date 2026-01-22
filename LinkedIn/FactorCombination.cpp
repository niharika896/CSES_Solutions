#include <bits/stdc++.h> 
using namespace std;
void dfs(int n,int start,vector<int>&curr,vector<vector<int>>&ans){
	if(n==1){
		if(curr.size()>1){
			ans.push_back(curr);
			return;
		}
	}
	for(int i=start;i*i<=n;i++){
		if(n%i==0){
			curr.push_back(i);
			dfs(n/i,i,curr,ans);
			curr.pop_back();
		}
	}
	if(!curr.empty()){
		curr.push_back(n);
		ans.push_back(curr);
		curr.pop_back();
	}

}

vector<vector<int>> factorCombinations(int n) 
{
	vector<vector<int>>ans;
	vector<int>curr;
	dfs(n,2,curr,ans);
	return ans;
	// Write your code here.
}