#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int m,n;
    cin >> m>>n;
    set<int>pos;
    multiset<int>lens;
    pos.insert(0);
    pos.insert(m);
    lens.insert(m);
    while(n--){
        int p;
        cin>>p;
        auto it = pos.lower_bound(p);
        int r=*it;
        it--;
        int l=*(it);
        auto it1=lens.find(r-l);
        lens.erase(it1);
        lens.insert(r-p);
        lens.insert(p-l);  
        pos.insert(p);
        cout<<*lens.rbegin()<<'\n';
    }
    return 0;
}