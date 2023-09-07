#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Hash{
	public:
	static const int n = 17;
	int hashid[n];
    string hashtable[n];
	Hash(){
		for(int i=0;i<n;i++){
			hashid[i] = -1;
            hashtable[i] = "-"; 
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
		if(hashid[index]==-1){
			hashid[index] = id;
		    hashtable[index] = data;
		}
		else{
			for(int i=1;i<n;i++){
				int h = (id+(i*f(id)))%n;
				if(hashid[h]==-1){
					hashid[h] = id;
					hashtable[h] = data;
					break;
 				}
			}
		}
	}
	string seach(int id){
        for(int i=0;i<n;i++){
            int k = (id+(i*f(id)))%n;
            if(hashid[k]==id){
				return hashtable[k];
			}
        }
		return "-";
	}
	void print(){
		for(int i=0;i<n;i++){
			cout<<"("<<hashid[i]<<","<<hashtable[i]<<")";
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