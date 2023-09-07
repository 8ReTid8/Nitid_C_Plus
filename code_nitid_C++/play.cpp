#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

class Stack{
    public:
    char arr[100];
    int top = 0;
    void push(char n){
        arr[top] = n;
        top++;
    }
    char pop(){
       return arr[--top];
    }
};


int main(){
    Stack q;
    char s[100];
    int n;
    cin>>s;
    for(int i=0;i<strlen(s);i++){
        q.push(s[i]);
    }
    for(int i=0;i<strlen(s);i++){
        cout<<q.pop();
    }
}