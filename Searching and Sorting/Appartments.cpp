#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,k;
    cin >> n;
    cin >> m;
    cin >> k;
    int count=0;
    vector<int>req(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }
    vector<int>apt(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> apt[i];
    }
    sort(req.begin(),req.end());//n
    sort(apt.begin(),apt.end());//m
    int i=0;int j=0;
    while(i<n && j<m){
        if(apt[j]<req[i]-k)j++;
        else if(apt[j]>req[i]+k)i++; 
        else{
            count++;
            i++;
            j++;
        }
    }

    cout<<count;
    return 0;
}