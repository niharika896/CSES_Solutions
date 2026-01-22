#include <bits/stdc++.h>

using namespace std;


class SpecialStack {
    private:
        stack<int>st;
        stack<int>maxStack;
  public:
    SpecialStack() {
    }

    void push(int x) {
        st.push(x);
        if(maxStack.empty() || maxStack.top()<=x){
            maxStack.push(x);
        }
    }

    void pop() {
        if(st.empty())return;
        if(st.top()==maxStack.top()){
            maxStack.pop();
        }
        st.pop();
    }

    int peek() {
        if(st.empty())return -1;
        return st.top();
    }

    bool isEmpty() {
        return st.empty();
    }

    int getMax() {
        if(maxStack.empty())return -1;
        return maxStack.top();
    }
};