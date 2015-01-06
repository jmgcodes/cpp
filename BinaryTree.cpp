/*
 * Program: Binary tree implementation
 * 
 * Author: Jwala Mohith Girisha
 * 
 */


#include<iostream>

using namespace std;

struct node{
	
	int key;
	struct node* left;
	struct node* right;
	
};


class btree{
	
	public:
		btree();
		~btree();
		
		void insert(int key);
		void delete_tree();
		node* search(int key);
		
		void display(int type);
		
	private:
		node* root;
		
		void insert(int key, node* leafnode);
		void delete_tree(node* leafnode);
		node* search(int key, node* leafnode);
	
		void display_pre(node* leafnode);
		void display_in(node* leafnode);
		void display_post(node* leafnode);

};

btree::btree(){
	
	root = NULL;
	
}

btree::~btree(){
	
	delete_tree();
	
}


void btree::insert(int key, node* leafnode){
	
	if(key < leafnode->key){
		if(leafnode->left != NULL)
			insert(key, leafnode->left);
		else{
			leafnode->left = new node;
			leafnode->left->key = key;
			leafnode->left->left = NULL;
			leafnode->left->right = NULL;
		}
	}
	else{
		if(leafnode->right != NULL)
			insert(key, leafnode->right);
		else{
			leafnode->right = new node;
			leafnode->right->key = key;
			leafnode->right->left = NULL;
			leafnode->right->right = NULL;
		}
	}	
}

void btree::insert(int key){
	
	if(root!=NULL)
		insert(key, root);
	else{
		root = new node;
		root->key = key;
		root->left = NULL;
		root->right = NULL;
	}
}

void btree::delete_tree(node* leafnode){
	
	if(leafnode!=NULL){
		delete_tree(leafnode->left);
		delete_tree(leafnode->right);
		delete(leafnode);
	}	
}

void btree::delete_tree(){
	
	delete_tree(root);
	
}

node* btree::search(int key, node* leafnode){
	
	if(leafnode!=NULL){
		if(leafnode->key == key)
			return leafnode;
		else if(leafnode->key > key)
			return search(key, leafnode->left);
		else
			return search(key, leafnode->right);
	}
	else return NULL;
	
}

node* btree::search(int key){

	return search(key,root);

}


void btree::display_pre(node* leafnode){
	
	if(leafnode!=NULL){
		cout << leafnode->key << endl;
		display_pre(leafnode->left);
		display_pre(leafnode->right);
	}
}

void btree::display_in(node* leafnode){
	
	if(leafnode!=NULL){
		display_in(leafnode->left);
		cout << leafnode->key << endl;
		display_in(leafnode->right);
	}
}

void btree::display_post(node* leafnode){
	
	if(leafnode!=NULL){
		display_post(leafnode->left);
		display_post(leafnode->right);
		cout << leafnode->key << endl;
	}
}

void btree::display(int type){
	
	switch(type){
	
		case 1:
			cout << "Pre-order display of binary tree\n";
			display_pre(root);
			break;
		case 2:
			cout << "In-order display of binary tree\n";
			display_in(root);
			break;
		case 3:
			cout << "Post-order display of binary tree\n";
			display_post(root);
			break;
		default:
			cout << "Invalid selection\n";
			break;
		}
}

int main(){
	
	btree binary_tree;
	
	binary_tree.insert(9);
	binary_tree.insert(4);
	binary_tree.insert(15);
	binary_tree.insert(6);
	binary_tree.insert(12);
	binary_tree.insert(17);
	binary_tree.insert(2);

	/*
	node* find_node = binary_tree.search(10);
	
	if(find_node->left!=NULL && find_node->right!=NULL)
		cout << "Node value: " << find_node->key << "\nThe key value of children are " << find_node->left->key << " and " << find_node->right->key << endl;
	else
		cout << "Node value: " << find_node->key << "\nNo children" << endl;
	*/
	
	binary_tree.display(1);
	binary_tree.display(2);
	binary_tree.display(3);
	
	
	return 0;
}
