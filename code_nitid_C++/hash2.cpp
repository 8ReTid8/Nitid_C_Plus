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
	int f(int id){
		return 11-(id%11);
	}
	void add(int id,string data){
		int index = hashfunc(id);
		if(arrhash[index]->id==-1){
			arrhash[index]->id = id;
		    arrhash[index]->val = data;
		}
		else{
			for(int i=1;i<n;i++){
				int h = (id+(i*f(id)))%n;
				if(arrhash[h]->id==-1){
					arrhash[h]->id = id;
					arrhash[h]->val = data;
					break;
 				}
			}
		}
	}
	string seach(int id){
		Node* ptr;
        for(int i=0;i<n;i++){
            int k = (id+(i*f(id)))%n;
            ptr = arrhash[k];
            if(ptr->id==id){
				return ptr->val;
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