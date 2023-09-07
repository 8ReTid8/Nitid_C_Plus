#include <iostream>
#include <cstring>
using namespace std;

class Stack{
	public:
	char a[100];
	int top = -1;
	void push(char item){
		a[++top]=item;
	}
	char pop(){
		return a[top--];
	}
};

int main(){
	Stack s;
	char type[100];
	int i;
	cin>>type;
	for(i=0;i<strlen(type);i++){
		s.push(type[i]);
	}
	for(i=0;i<strlen(type);i++){
		cout<<s.pop();
	}
	return 0;
}
