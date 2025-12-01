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
    //requirements array
    vector<int>req(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> req[i];
    }
    //array of available aps
    vector<int>apt(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> apt[i];
    }
    //sorting them
    sort(req.begin(),req.end());//n
    sort(apt.begin(),apt.end());//m
    int i=0;int j=0;
    while(i<n && j<m){
        if(apt[j]<req[i]-k)j++; //apartment too small move on to the next bigger apt
        else if(apt[j]>req[i]+k)i++; //apt too big move on to the next bigger buyer
        else{ //perfect match accept this
            count++;
            i++;
            j++;
        }
    }

    cout<<count;
    return 0;
}

//sorting the arrays makes it easy to eliminate demands that most certainly wont be met reducing complexity.