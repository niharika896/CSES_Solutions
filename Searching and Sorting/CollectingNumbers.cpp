#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //4 2 1 5 3
    vector<int>pos(n+1,-1);
    for(int i=0;i<n;i++){
        pos[a[i]]=i;
    }
    //-1 2 1 4 0 3
    int count=1;
    for(int i=2;i<=n;i++){
        if(pos[i]<pos[i-1])count++;
    }
    cout<<count;
    return 0;
}