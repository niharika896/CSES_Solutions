#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int>og=a;
    sort(a.begin(),a.end());
    int l=0,r=n-1;
    int pos=0;
    while(l<r){
        if(a[l]+a[r]==x){
            pos=1;
            break;
        }
        else if(a[l]+a[r]>x){
            r--;
        }
        else{
            l++;
        }
    }
    if(!pos){
        cout<<"IMPOSSIBLE";
    }
    else{
        int t=0;
        int t1=a[l];
        int t2=a[r];
        for(int i=0;i<n;i++){
            if(t<=1){
                if(og[i]==t1){
                t1=INT_MAX;
                cout<<i+1<<" ";
                t++;
            }
            else if(og[i]==t2){
                t2=INT_MAX;
                cout<<i+1<<" ";
                t++;
            }
            }
        }
    }
    return 0;
}