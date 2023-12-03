#include <bits/stdc++.h>
using namespace std;

class Node
{
	public:
	int key;
	Node *left;
	Node *right;
	int height;
};

int height(Node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

int max(int a, int b)
{
	return (a > b)? a : b;
}

Node* newNode(int key)
{
	Node* node = new Node();
	node->key = key;
	node->left = NULL;
	node->right = NULL;
	node->height = 1; 

	return(node);
}


Node *rightRotate(Node *y){
	Node *x = y->left;
	Node *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Update heights
	y->height = max(height(y->left),height(y->right)) + 1;
	x->height = max(height(x->left),height(x->right)) + 1;

	// Return new root
	return x;
}


Node *leftRotate(Node *x)
{
	Node *y = x->right;
	Node *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Update heights
	x->height = max(height(x->left),height(x->right)) + 1;
	y->height = max(height(y->left),height(y->right)) + 1;

	// Return new root
	return y;
}

// Get Balance factor of node N
int getBalance(Node *N)
{
	if (N == NULL)
		return 0;
	return height(N->left) - height(N->right);
}


Node* insert(Node* node, int key)
{
	/* 1. Perform the normal BST insertion */
	if (node == NULL)
		return(newNode(key));
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);
	else // Equal keys are not allowed in BST
		return node;

	/* 2. Update height of this ancestor node */
	node->height = 1 + max(height(node->left),height(node->right));


	int balance = getBalance(node);

	if (balance > 1 && key < node->left->key)
		return rightRotate(node);

	if (balance < -1 && key > node->right->key)
		return leftRotate(node);

	// Left Right Case
	if (balance > 1 && key > node->left->key){
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}

	// Right Left Case
	if (balance < -1 && key < node->right->key){
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}

	/* return the (unchanged) node pointer */
	return node;
}
Node *minValueNode(Node* node){
    Node* current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
 
    return current;
}
 

Node* deleteNode(Node* root, int key){
     
    // STEP 1: PERFORM STANDARD BST DELETE
    if (root == NULL)
        return root;
 
  
    if ( key < root->key )
        root->left = deleteNode(root->left, key);
 
   
    else if( key > root->key )
        root->right = deleteNode(root->right, key);
 
    
    else{
        // node with only one child or no child
        if( (root->left == NULL) ||(root->right == NULL) ){
            Node *temp = root->left ? root->left : root->right;
 
            if (temp == NULL){
                temp = root;
                root = NULL;
            }
            else 
            *root = *temp; 
            free(temp);
        }
        else{
            Node* temp = minValueNode(root->right);
 
            // Copy the inorder successor's
            // data to this node
            root->key = temp->key;
 
            // Delete the inorder successor
            root->right = deleteNode(root->right,temp->key);
        }
    }
 
    if (root == NULL)
    return root;
 
    root->height = 1 + max(height(root->left),height(root->right));
 
 
    int balance = getBalance(root);
 
 
    // Left Left Case
    if (balance > 1 &&getBalance(root->left) >= 0)
        return rightRotate(root);
 
    // Left Right Case
    if (balance > 1 &&getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
 
    // Right Right Case
    if (balance < -1 &&getBalance(root->right) <= 0)
        return leftRotate(root);
 
    // Right Left Case
    if (balance < -1 &&getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
 
    return root;
}

void preOrder(Node *root)
{
	if(root != NULL){
		cout << root->key << " ";
		preOrder(root->left);
		preOrder(root->right);
	}	
}


int main(){
	Node *root = NULL;
	int n;
	char s;
	while(true){
		cin>>s;
		if(s=='a'){
			cin>>n;
			root = insert(root,n);
		}
		if(s=='d'){
			cin>>n;
			root = deleteNode(root,n);
		}
		if(s=='p'){
			preOrder(root);
			cout<<endl;
		}
		if(s=='x'){
			break;
		}
	}
	return 0;
}



