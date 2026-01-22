#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int m;
    cin >> n>>m;
    vector<int> a(n+1, 0);
    vector<int>pos(n+1,0);
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
        pos[a[i]]=i;
    }
    int rounds=1;
    for(int i=2;i<=n;i++){
        if(pos[i]<pos[i-1])rounds++;
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        int x=a[l], y=a[r];
        set<int>s={x,x+1,y,y+1};
        for(auto i:s){
            if(i>=2 && i<=n && pos[i]<pos[i-1])rounds--;
        }
        swap(a[l],a[r]);
        pos[a[l]]=l;
        pos[a[r]]=r;

        for(auto i:s){
            if(i>=2 && i<=n && pos[i]<pos[i-1])rounds++;
        }
        cout<<rounds<<endl;
    }
    return 0;
}