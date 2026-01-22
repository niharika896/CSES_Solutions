#include <bits/stdc++.h>
using namespace std;
class RandomizedSet {
private:
    unordered_map<int,int>mp;//val,ind
    vector<int>v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(!mp.count(val)){
            mp[val]=v.size();
            v.push_back(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(!mp.count(val))return false;
        int idx=mp[val];
        int last=v.back();

        v[idx]=last;
        mp[last]=idx;

        v.pop_back();
        mp.erase(val);

        return true;
    }
    
    int getRandom() {
        int n=mp.size();
        int r=rand() % v.size();
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */