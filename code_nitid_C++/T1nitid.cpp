#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class node{
	public:
		node *right;
		node *left;
		int value;
		node(int v){
			value = v;
			left = NULL;
			right = NULL;
		}
//		node(){
//			value = NULL;
//			left = NULL;
//			right = NULL;
//		}
};
class tree{
	public:
		node *r;
//		tree(){
//			r = new node();
//		}
		void addnode(int value){
			node *n = r;
			if(r == NULL){
				r = new node(value);
			}
			else{
				while(true){
					if(n->value>value&&n->left!=NULL){
						n = n->left;
					}
					else if(n->value<=value&&n->right!=NULL){
						n = n->right;
					}
					else if(n->value>value&&n->left==NULL){
						n->left = new node(value);
						break;
					}
					else if(n->value<=value&&n->right==NULL){
						n->right = new node(value);
						break;
					}
					else {
						break;
					}
				}
			}
		}
		
		
		bool search(int value){
			node *n = r;
			while(true){
				if(n->value>value&&n->left!=NULL){
					n = n->left;
				}
				else if(n->value<value&&n->right!=NULL){
					n = n->right;
				}
				else if(n->value==value){
					return true;
				}
				else{
					return false;
				}
			}
		}
		
		void deletenodechild(node *n){
			if(n->right->left==NULL){
				int s = n->right->value;
				deletenode(s);
				n->value = s;
			}
			else{
				node *tn = n->right;
				while(true){
					if(tn->left==NULL){
						break;
					}
					tn = tn->left;
				}
				int s = tn->value;
				deletenode(s);
				n->value = s;
			}
		}
		
		void deletenode(int v){
			if(!search(v)){
				if(r->value==v&&r->left==NULL&&r->right==NULL){
					return;
				}
				else if(r->value==v&&r->left==NULL&&r->right!=NULL){
					r = r->right;
				}
				else if(r->value==v&&r->left!=NULL&&r->right==NULL){
					r = r->left;
				}
				else if(r->value==v&&r->left!=NULL&&r->right!=NULL){
					deletenodechild(r);
				}
			}
			else{
				node *p = r;
				while(true){
					
					if(p->value>v&&p->left!=NULL){
						node *c = p->left;
						if(c->value==v){
							if(c->left==NULL&&c->right==NULL){
								p->left=NULL;
								return;
							}
							else if(c->left==NULL&&c->right!=NULL){
								p->left=c->right;
								return;
							}
							else if(c->left!=NULL&&c->right==NULL){
								p->left=c->left;
								return;
							}
							else if(c->left!=NULL&&c->right!=NULL){
								deletenodechild(c);
								return;
							}
						}
						p = p->left;
					}
					else if(p->value<v&&p->right!=NULL){
						node *c = p->right;
						if(c->value==v){
							if(c->left==NULL&&c->right==NULL){
								p->right=NULL;
								return;
							}
							else if(c->left==NULL&&c->right!=NULL){
								p->right=c->right;
								return;
							}
							else if(c->left!=NULL&&c->right==NULL){
								p->right=c->left;
								return;
							}
							else if(c->left!=NULL&&c->right!=NULL){
								deletenodechild(c);
								return;
							}
						}
						p = p->right;
					}
				}
			}
		}
		
		void preorder(node* n){
			if(n!=NULL){
				cout<<n->value<<",";
				preorder(n->left);
				preorder(n->right);
			}
		}
		
		void inorder(node* n){
			if(n!=NULL){
				inorder(n->left);
				cout<<n->value<<",";
				inorder(n->right);
			}
		}
		
		void postorder(node* n){
			if(n!=NULL){
				postorder(n->left);
				postorder(n->right);
				cout<<n->value<<",";
			}
		}
		
		int h=0,th = -1;
		void h_height(node *n){
			if(n!=NULL){
				th++;
				h_height(n->left);
				h_height(n->right);
				if(th>h){
					h = th;
				}
				th--;
			}
		}
		int height(int v){
			node *n = r;
			while(true){
				if(n->value>v&&n->left!=NULL){
					n = n->left;
				}
				else if(n->value<v&&n->right!=NULL){
					n = n->right;
				}
				else if(n->value==v){
					h = 0,th = -1;
					h_height(n);
					return h;
				}
				else{
					return -1;
				}
			}
		}
		void printlevel(node *n,int level){
			if(level==0){
				cout<<n->value<<",";
			}
			else{
				if(n->left != NULL){
					printlevel(n->left,level-1);
				}
				if(n->right != NULL){
					printlevel(n->right,level-1);
				}
			}
		}
		void bft(){
			for(int i=0;i<=height(r->value);i++){
				printlevel(r,i);
				cout<<"|";
			}
			cout<<endl;
		}
};

int main(){
	int n;
	char s;
	tree *a = new tree();
	while(true){
		cin>>s;
		if(s=='a'){
			cin>>n;
			a->addnode(n);	
		}
		if(s=='d'){
			cin>>n;
			a->deletenode(n);
		}
		if(s=='b'){
			a->bft();
		}
		if(s=='i'){
			a->inorder(a->r);
			cout<<endl;
		}
		if(s=='p'){
			a->preorder(a->r);
			cout<<endl;
		}
		if(s=='t'){
			a->postorder(a->r);
			cout<<endl;
		}
		if(s=='x'){
			break;
		}
	}
	
}
