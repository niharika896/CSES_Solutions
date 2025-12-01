#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
int main()
{

    int n,m;
    cin >> n;
    cin>>m;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    int l=0;int r=n-1;
    int count=0;
    while(l<=r){
        if(a[l]+a[r]<=m){
            count++;
            l++;r--;
        }
        else{
            count++;
            r--;
        }
    }
    cout<<count;
    return 0;
}

//the problem restricts no of children in a gondola to 1 or 2 thus the most efficient strategy is to combine the heaviest and lightest child together progressively from both ends