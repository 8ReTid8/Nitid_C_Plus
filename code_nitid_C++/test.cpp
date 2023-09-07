#include <iostream>
using namespace std;

class stack{
    public:
    int arr[100];
    int top = -1;
    // void push(int x){
    //     top++;
    //     arr[top] = x;
    // }
    // void pop(){
    //     if(top<0){
    //         cout<<-1<<endl;
    //     }
    //     else{
    //         cout<<arr[top]<<endl;
    //         top--;
    //     }    
    // }
    // void print(){
    //     for(int i=0;i<=top;i++){
    //         cout<<arr[i]<<" ";
    //     }
    //     cout<<endl;
    // }
};
int main(){
    stack s;
    char a;
    int n;
    while(true){
        cin>>a;
        if(a=='p'){
            cin>>n;
            s.push(n);
        }
        if(a=='o'){
            s.pop();
        }
        if(a=='d'){
            s.print();
        }
        if(a=='x'){
            break;
        }
    }
   
}