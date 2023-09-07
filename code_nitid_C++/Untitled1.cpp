#include <iostream>

using namespace std;

int main(){
	int x=3;
	cout<<"hello word "<<x<<endl;
	cout<<"enter ";
	cin>>x;
	cout<<x<<endl;
	if(x>0){
		cout<<"true";
	}
	while(true){
		cout<<x++;
	}
	return 0;
} 
