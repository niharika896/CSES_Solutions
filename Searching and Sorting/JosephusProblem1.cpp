#include <bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node* next;
    Node* prev;

    Node(int val){
        this->val=val;
        this->next=nullptr;
        this->prev=nullptr;
    }
};

void removeNode(Node* node){
    node->prev->next=node->next;
    node->next->prev=node->prev;
    delete node;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    Node* head=new Node(1);
    Node* curr=head;
    for(int i=2;i<=n;i++){
        Node* temp=new Node(i);
        temp->prev=curr;
        curr->next=temp;
        curr=temp;
    }
    curr->next=head;
    head->prev=curr;

    vector<int>ans;
    curr=head;
    int rem=n;
    while(rem>1){
        curr=curr->next;
        ans.push_back(curr->val);
        Node* nextNode=curr->next;
        if(curr==head){
            head=nextNode;
        }
        removeNode(curr);
        curr=nextNode;
        rem--;
    }
    ans.push_back(head->val);
    delete head;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}