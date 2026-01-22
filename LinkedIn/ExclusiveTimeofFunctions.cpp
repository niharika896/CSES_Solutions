#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
       vector<int>times(n,0);
       int last=0;
       stack<int>st;
       int prevTime=0;
       for(string log:logs){
        int id=stoi(log.substr(0,log.find(':')));
        bool isStart=log.find("start")!=string::npos;
        int time = stoi(log.substr(log.rfind(':')+1));

        if(isStart){
            if(!st.empty()){
                times[st.top()]+=time-prevTime;
            }
            st.push(id);
            prevTime=time;
        }else{
            times[st.top()]+=time-prevTime+1;
            st.pop();
            prevTime=time+1;
        }
       }
       return times;
    }
};