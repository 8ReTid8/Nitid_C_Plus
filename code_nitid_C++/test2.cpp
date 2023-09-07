#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class que{
    public:
    int arr[100];
    int head=0;
    int tail=-1;
    int size = 0;
    void push(int x){
        tail++;
        arr[tail] = x;
        size++;
    }
    void out(){
        if(size==0){
            cout<<"emty"<<endl;
        }
        else{
            cout<<arr[head]<<endl;
            head++;
            size--;
        }
        
    }
    void print(){
        for(int i=head;i<=
        tail;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    que q;
    char c;
    int n;
    while(true){
        cin>>c;
        if(c=='p'){
            cin>>n;
            q.push(n);
        }
        if(c=='o'){
            q.out();
        }
        if(c=='s'){
            q.print();
        }
        if(c=='e'){
            break;
        }
    }
}