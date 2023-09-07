#include <iostream>
#include <cstring>
using namespace std;
class Node{
	public:
		int data;
		Node *next=NULL;
		Node *prev=NULL;
		Node(int data){
			this->data = data;
		}
};

class linklist{
	public:
		Node *head;
		linklist():head(nullptr){
		}
		int search(int pos){
			Node *ptr = head;
			int i=0;
			while(ptr!=NULL){
				if(ptr->data == pos){
					return i;
				}
				else{
					ptr = ptr->next;
					i++;
				}
			}
			return -1;
		}
		
		void push_front(int data){
			Node *x = new Node(data);
			x->next = head;
			head = x;
		}
		
		int erase(int id){
			Node *x = head;
			Node *y = head;
			int position = search(id);
			for(int i=0;i<position-1;i++){
				y = y->next;
			}
			x = y->next;
			y->next = y->next->next;
			return x->data;
		}
		
		void insertafter(int data,int pos){
			Node *x = new Node(data);
			Node *y = head;
			int position = search(pos);
		
			for(int i=0;i<position;i++){
				y = y->next;
			}
			x->next=y->next;
			y->next=x;
		}
		void insertbefore(int data,int pos){
			Node *x = new Node(data);
			Node *y = head;
			int position = search(pos);
			if(position==0){
				push_front(data);
				return;
			} else if (position == -1) {
				insert(data);
				return;
			}
			for(int i=0;i<position-1;i++){
				y = y->next;
			}
			x->next=y->next;
			y->next=x;
		}
		
		void print(){
			Node *x = head;
			while(x!=NULL){
				cout<<x->data<<endl;
				x = x->next;
			} 
		}
		
		void insert(const int& value) {
			Node* newNode = new Node(value);
			if(!head) {
				head = newNode;
			} 
			else {
				Node* ptr = head;
				while(ptr) {
					ptr = ptr->next;
				}
				ptr->next = newNode;
			}
		}
};

int main(){
	char s;
	int n,id,i=1;
	linklist *a = new linklist();
	while(i==1){
		cin>>s;
		switch (s){
			case 'A':
				cin>>n;
				cin>>id;
				a->insertafter(n,id);
				a->print();
				break;
			case 'I':
				cin>>n;
				cin>>id;
				a->insertbefore(n,id);
				a->print();
				break;
			case 'D':
				cin>>id;
				a->print();
				break;
			case 'E':
				i = 0;
		}
		
	}
//	linklist *a = new linklist(3);
//	a->push_front(5);
//	a->push_front(6);
//	a->print();
	return 0;
}

