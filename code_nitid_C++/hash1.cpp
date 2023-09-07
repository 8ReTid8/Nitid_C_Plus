#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		Node* next;
		int id;
		string val;
		Node(int id,string val){
			this->id = id;
			this->next = NULL;
			this->val = val;
		}
};

class Hash{
	public:
	static const int n = 17;
	Node* arrhash[n];
	Hash(){
		for(int i=0;i<n;i++){
			Node* newnode = new Node(-1,"-");
			arrhash[i] = newnode;
		}
	}
	
	int hashfunc(int id){
		return id%n;
	}
	void add(int id,string data){
		int index = hashfunc(id);
		if(arrhash[index]->id==-1){
			arrhash[index]->id = id;
		    arrhash[index]->val = data;
		}
		else{
			Node* newnode = new Node(id,data);
			Node* current = arrhash[index];
			while(current->next!= NULL){
				current = current->next;
			}
			current->next = newnode;
		}
	}
	string seach(int id){
		int k = hashfunc(id);
		Node* ptr;
		ptr = arrhash[k];
		while(ptr!=NULL){
			if(ptr->id==id){
				return ptr->val;
                break;
			}
			else{
				ptr = ptr->next;
			}
		}
		return "-";
	}
	void print(){
		for(int i=0;i<n;i++){
			cout<<"("<<arrhash[i]->id<<","<<arrhash[i]->val<<")";
			Node * current = arrhash[i]; 
			while(current->next!=NULL){
				cout<<"("<<current->next->id<<","<<current->next->val<<")";
				current=current->next;
			}
			cout<<endl;
		}
	}
};
int main(){
	Hash h;
	char s;
	string c; 
	int n;
	while(true){
		cin>>s;
		if(s=='a'){
			cin>>n;
			cin>>c;
			h.add(n,c);
		}
		if(s=='s'){
			cin>>n;
			cout<<h.seach(n)<<endl;
		}
		if(s=='p'){
			h.print();
		}
		if(s=='e'){
			break;
		}
	}
	return 0;
}