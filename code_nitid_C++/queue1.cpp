#include <iostream>
#include <cstring>
using namespace std;
class que{
	public:
	int arr[5];
	int head = 0;
	int tail = -1;
	int quesize = 0;
	void add(int x){
		if(quesize>=5){
			cout<<"full"<<endl;
		}
		else if(tail==4){
			tail = 0;
			quesize++;
			arr[tail] = x;
		}
		else{
			tail++;	
			quesize++;
	 	 	arr[tail] = x;
		}
	}
	int deque(){
		if(quesize<=0){
			cout<<"empty"<<endl;
			return -1;
		}
		else if(head>4){
			head = 0;
			int y = arr[head];
			quesize--;
			return y;
		}
		else{
			int y = arr[head];
			quesize--;
			head++;
			return y;
		}	
	}
	
	void p(){
		if(head>=0&&tail>=0){
			if(head<=tail){
				for(int i=head;i<=tail;i++){
					cout<<arr[i]<<" ";
				}
				cout<<endl;
			}
			else{
				for(int i=head;i<quesize;i++){
					cout<<arr[i]<<" ";
				}
				for(int i=0;i<=tail;i++){
					cout<<arr[i]<<" ";
				}
				cout<<endl;
			}
		}
	}
	
	void s(){
		cout<<arr[head]<<" "<<arr[tail]<<endl;
	}
	void n(){
		cout<<quesize<<endl;
	}
	
};

int main(){
	que q;
	char s;
	int n;
	while(true){
		cin>>s;
		if(s=='e'){
			cin>>n;
			q.add(n);
		}
		if(s=='d'){
			cout<<q.deque()<<endl;
		}
		if(s=='p'){
			q.p();
		}
		if(s=='n'){
			q.n();
		}
		if(s=='s'){
			q.s();
		}
		if(s=='x'){
			break;
		}
	}
}
