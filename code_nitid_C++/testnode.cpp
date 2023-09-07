#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node{
    public:
    Node *next;
    int id;
    Node(int id){
        this->id = id;
        this->next = NULL;
    }
};
class linklist{
    public:
    Node *head = NULL;
    int seach(int id){
        Node* ptr = head;
        int i=0;
        while(ptr!=NULL){
            if(ptr->id==id){
                return i;
            }
            else{
                ptr = ptr->next;
                i++;
            }
        }
        return -1;
    }
    void del(int id){
        Node* ptr = head;
        int index = seach(id);
        for(int i=0;i<index-1;i++){
            ptr = ptr->next;   
        }
        ptr->next = ptr->next->next;
    }
    void add(int id){
        Node *newnode = new Node(id);
        if(head==NULL){
            head = newnode;
        }
        else{
            Node *ptr = head;
            while(ptr->next!=NULL){
                ptr = ptr->next; 
            }
            ptr->next = newnode;
        }
    }
    void print(){
        Node *i = head;
        while(i!=NULL){
            cout<<i->id<<" ";
            i = i->next;
        }
        cout<<endl;
    }
};
int main(){
    linklist *a = new linklist();
    int n;    
    char s;
    while(true){
        cin>>s;
        if(s=='a'){
            cin>>n;
            a->add(n);
        }
        if(s=='p'){
            a->print();
        }
        if(s=='d'){
            cin>>n;
            a->del(n);
        }
        if(s=='f'){
            cin>>n;
            cout<<a->seach(n)<<endl;
        }
    }
}