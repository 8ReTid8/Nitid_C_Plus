#include <bits/stdc++.h>
using namespace std;

class graph{
	public:
	int edge[100][100];
	int size ;
	graph(int n){
		size = n;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				edge[i][j] = 0;
			}
		}
	}
	void add_edge(int x,int y,int n){
		edge[x][y] = n;
	}
	void bft(int start){
		bool visitbft[100];
		for(int i=0;i<100;i++){
			visitbft[i] = 0;
		}
		visitbft[start] = 1; 
		vector<int> q;
		q.push_back(start);
		while(q.empty()==0){
			start = q.front();
			cout<<start<<" ";
			q.erase(q.begin());
			for(int j=0;j<size;j++){
				if(visitbft[j]==0&&edge[start][j]>0){
					visitbft[j] = 1;
					q.push_back(j);
				}
			}
		}
	}
	bool visitdft[100];
	void subdft(int start){
		cout<<start<<" ";
		visitdft[start] = 1;
		for(int i=0;i<size;i++){
			if(visitdft[i]==0&&edge[start][i]>0){
				subdft(i);
			}
		}
	}
	void dft(int start){
		for(int i=0;i<100;i++){
			visitdft[i] = 0;
		}
		subdft(start);
	}
};

int main(){
	
	int size;	
	int r,c,w;
	char s;
	cin>>size;
	graph g(size);
	while(true){
		cin>>s;
		if(s=='e'){
			cin>>r;
			cin>>c;
			cin>>w;
			g.add_edge(r,c,w);
		}
		
		if(s=='d'){
			cin>>r;
			g.dft(r);
			cout<<endl;
			
		}
		if(s=='b'){
			cin>>r;
			g.bft(r);
			cout<<endl;
		}
		if(s=='q'){
			break;
		}
	}
}

