#include <iostream>
using namespace std;
class Node{
	public:
		int value;
		Node *right;
		Node *left;
		Node(int d){
			value = d;
			left = NULL;
			right = NULL;
		}
		Node(){
			value = NULL;
			left = NULL;
			right = NULL;
		}
};
class Tree{
	public:
		Node *r;
		Tree(){
			r= new Node();
		}
		bool search(int value){
			Node *n= r;
			while(true){
				if(value == n->value){
					return n->value;
				}
				else if(value > n->value && n->right != NULL){
					n = n->right;
				}
				else if(value < n->value && n->left != NULL){
					n = n->left;
				}
				else if(n->value == value)
					return true;
				else{
					return false;
				}
			}
		}
		void add(int value){
			Node *n = r;
			while(true){
				if(n->value > value && n->left != NULL){
					n=n->left;
				}else if(n->value <= value && n->right != NULL){
					n = n->right;
				}else if(n->value > value && n->left == NULL){
					n->left = new Node(value);
					break;
				}else if(n->value <= value && n->right == NULL){
					n->right = new Node(value);
					break;
				}else{
					break;
				}
			}
		}
		void preorder_traversal(Node *n){
			if(n != NULL){
				if(n->value != 0)
					cout << n->value <<",";
				preorder_traversal(n->left);
				preorder_traversal(n->right);
			}
		}
		void inorder_traversal(Node *n){
			if(n != NULL){
				inorder_traversal(n->left);
				if(n->value != 0)
					cout << n->value <<",";
				inorder_traversal(n->right);
			}
		}
		void postorder_traversal(Node *n){
			if(n != NULL){
				postorder_traversal(n->left);
				postorder_traversal(n->right);
				if(n->value != 0)
					cout << n->value <<",";
			}
		}
		int depth(int v){
			int d =0;
			Node *n = r;
			while(true){
				if(n->value > v && n->left != NULL){
					n = n->left;
					d++;
				}else if(n->value < v && n->right != NULL){
					n = n->right;
					d++;
				}else if(n->value == v){
					return d;
				}else{
					return - 1;
				}
			}
		}
		int h=0,t_h = -1;
		void h_height(Node *n){
			if(n != NULL){
				t_h++;
				h_height(n->left);
				h_height(n->right);
				if(t_h > h){
					h = t_h;
				}
				t_h--;
			}
		}
		int height(int v){
			Node *n = r;
			while(true){
				if(n->value > v && n->left != NULL){
					n=n->left;
				}else if(n->value < v && n->right != NULL){
					n = n->right;
				}else if(n->value == v){
					h=0,t_h = -1;
					h_height(n);
					return h;
				}else{
					return -1;
				}
			}
		}
		void print_level(Node *n,int level){
			if(level == 0){
				cout << n->value << ",";
			}else{
				if(n->left != NULL){
					print_level(n->left,level-1);
				}if(n->right != NULL){
					print_level(n->right,level-1);
				}
			}
		}
		void breadth_first_traversal(){
			for(int i =1;i<=height(r->value);i++){
				print_level(r,i);
				cout << "|";
			}
			cout <<endl;
		}
		void delete_node_child(Node *n){
			if(n->right->left == NULL){
				int s = n->right->value;
				delete_node(s);
				n->value = s;
			}else{
				Node *tn = n->right;
				while(true){
					if(tn->left == NULL){
						break;
					}
					tn = tn->left;
				}
				int s = tn->value;
				delete_node(s);
				n->value = s;
			}
		}
		void delete_node(int v){
			if(!(search(v))){
				if(r->value == v && r->left == NULL && r->right==NULL){
					return;
				}else if(r->value == v && r->left == NULL && r->right != NULL){
					r=r->right;
				}else if(r->value == v && r->left != NULL && r->right == NULL){
					r=r->left;
				}else if(r->value == v && r->left != NULL && r->right != NULL){
					delete_node_child(r);
				}
			}else{
				Node *p = r;
				while(true){
					if(p->value > v && p->left != NULL){
						Node *c= p->left;
						if(c->value == v){
							if(c->left == NULL && c->right == NULL){
								p->left = NULL;
								return;
							}
							else if( c->left == NULL && c->right != NULL){
								p->left = c->right;
								return;
							}
							else if(c->left != NULL && c->right == NULL){
								p->left = c->left;
								return;
							}else if(c->left != NULL && c->right != NULL){
								delete_node_child(c);
								return;
							}
						}
						p=p->left;
					}
					else if(p->value < v && p->right != NULL){
						Node *c = p->right;
						if(c->value == v){
							if(c->left == NULL && c->right == NULL){
								p->right = NULL;
								return;
							}else if(c->left == NULL && c->right != NULL){
								p->right = c->right;
								return;
							}else if(c->left != NULL && c->right == NULL){
								p->right = c->left;
								return;
							}else if(c->left != NULL && c->right != NULL){
								delete_node_child(c);
								return;
							}
						}
						p=p->right;
					}
				}
			}
		}
};
int main(){
	int n;
	char s;
	Tree *ar = new Tree();
	while(true){
		cin >> s;
		if(s=='a'){
			int value;
			cin >> value;
			ar->add(value);
		}
		if(s=='d'){
			int value;
			cin >> value;
			ar->delete_node(value);
		}
		if(s=='b'){
			ar->breadth_first_traversal();
		}
		if(s=='i'){
			ar->inorder_traversal(ar->r);
			cout << endl;
		}
		if(s=='p'){
			ar->preorder_traversal(ar->r);
			cout << endl;
		}
		if(s=='t'){
			ar->postorder_traversal(ar->r);
			cout << endl;
		}
		if(s=='x'){
			break;
		}
	}
}
