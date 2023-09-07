#include <iostream>
#include <cstring>
using namespace std;

class Stack{
	public:
	int a[100];
	int top = -1;
	void u(int item){
		a[++top]=item;
	}
	void o(){
		cout<<a[top]<<endl;
		top--;
	}
	void t(){
		cout<<a[top]<<endl;
	}
	void p(){
		int i;
		for(i=0;i<=top;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
	void n(){
		cout<<top+1<<endl;
	}
};

int main(){
	Stack s;
	char n;
	int a;
	while(true){
		cin>>n;
		if(n=='U'){
			cin>>a;
			s.u(a);
		}
		if(n=='O'){
			s.o();
		}
		if(n=='T'){
			s.t();
		}
		if(n=='P'){
			s.p();
		}
		if(n=='N'){
			s.n();
		}
		if(n=='X'){
			break;
		}
	}
}
