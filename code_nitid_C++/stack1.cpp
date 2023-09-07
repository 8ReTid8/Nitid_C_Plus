#include <iostream>
#include <cstring>
using namespace std;

class Stack{
	public:
	char a[100];
	int top = -1;
	void push(int item){
		a[++top]=item;
	}
	char pop(){
		return a[top--];
	}
	bool empty(){
		if(top<=-1){
			return true;
		}
		else{
			return false;
		}
	}	
};

int main(){
	Stack a;
	string b;
	bool logic = true;
	cin>>b;
	for(int i=0;i<b.length();i++){
		if(b[i]=='('){
			a.push(b[i]);
		}
		else if(b[i]==')'){
			if(a.empty()){
				logic = false;
			}
			else{
				a.pop();
			}
		}
	}
	if(logic && a.empty()){
		cout<<"Pass";
	}
	else{
		cout<<"Error";
	}
}
