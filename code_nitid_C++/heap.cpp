#include <iostream>
#include <bits/stdc++.h>
#include <climits>
using namespace std;
class heap{
	public:
	int arr[100];
	int size = 0;
	int temp;
	
	void add(int n){
		size++;
		arr[size] = n;
	}
	int del(){
		if(size > 0){
				int s= arr[1];
				arr[1] = arr[size];
				size = size-1;
				int p = 1;
				while(p <= size){
					int l = p*2;
					int r = (p*2) + 1;
					if(l <= size && arr[l] > arr[p] && arr[l] >=arr[r]){
						int t= arr[l];
						arr[l] = arr[p];
						arr[p] = t;
						p = l;
					}else if(r <= size && arr[r] > arr[p] && arr[r] >arr[l]){
						int t= arr[r];
						arr[r] = arr[p];
						arr[p] = t;
						p = r;
					}else{
						break;
					}
				}
				return s;
			}else{
				return NULL;
			}
	}

	void sort(){
		int i = size;
		if(i%2==0){
			arr[i+1] = -9999;
		}
		else{
			i -= 1;
		}
		while(i>=1){
			int j = i;
			while(j<=size){
				int p = j/2;
				int r = j+1;
				int l = j;
				if(arr[l]>arr[r]&&arr[l]>arr[p]){
					temp = arr[l];
					arr[l] = arr[p];
					arr[p] = temp;
					j = 2*l;
				}
				else if(arr[r]>arr[l]&&arr[r]>arr[p]){
					temp = arr[r];
					arr[r] = arr[p];
					arr[p] = temp;
					j = 2*r;
				}
				else{
					break;
				}
			}
			i -= 2;
		}
	}
	void print(){
		for(int i=1;i<=size;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}
};
int main(){
	heap h;
	char s;
	int n;
	while(true){
		cin>>s;
		if(s=='a'){
			cin>>n;
			h.add(n);
			h.sort();
		}
		if(s=='d'){
			cout<<h.del()<<endl;
		}
		if(s=='p'){
			h.print();
		}
		if(s=='e'){
			break;
		}
	}
}
