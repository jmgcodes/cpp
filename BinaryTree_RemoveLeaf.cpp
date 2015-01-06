/*
 * Program: Binary tree implementation to remove a particular node
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
		node* find_parent(node* child);
		
		void delete_node();
		
	private:
		node* root;
		
		void insert(int key, node* leafnode);
		void delete_tree(node* leafnode);
		node* search(int key, node* leafnode);
		
		node* delete_node(node* start, int value);
		node* find_parent(node* start, node* child);
		node* min_node(node* start);
	
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


node* btree::find_parent(node* start, node* child){
	
	if(start!=NULL){
		if(start->left == child || start->right == child)
			return start;
		else if(start->key > child->key)
			return find_parent(start->left, child);
		else
			return find_parent(start->right, child);
	}
	else return NULL;
	
}

node* btree::find_parent(node* child){
	
	return find_parent(root, child);
	
}


node* btree::min_node(node* start)
{
    node* temp = start;

    while (temp->left != NULL)
        temp = temp->left;

    return temp;
}

node* btree::delete_node(node* start, int value){
	
    if (start == NULL) return start;

    if (value < start->key)
        start->left = delete_node(start->left, value);
    else if (value > start->key)
        start->right = delete_node(start->right, value);
    else
    {
        if (start->left == NULL)
        {
            struct node *temp = start->right;
            return temp;
        }
        else if (start->right == NULL)
        {
            struct node *temp = start->left;
            return temp;
        }

        struct node* temp = min_node(start->right);

        start->key = temp->key;

        start->right = delete_node(start->right, temp->key);
    }
    
    return start;	
}

void btree::delete_node(){
	
	cout << "Enter node to delete: ";
	int delete_node_value;
	cin >> delete_node_value;
	
	root = delete_node(root, delete_node_value);
	
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
	
	binary_tree.insert(50);
	binary_tree.insert(30);
	binary_tree.insert(20);
	binary_tree.insert(40);
	binary_tree.insert(70);
	binary_tree.insert(60);
	binary_tree.insert(80);
	

	/*
	node* find_node = binary_tree.search(10);
	
	if(find_node->left!=NULL && find_node->right!=NULL)
		cout << "Node value: " << find_node->key << "\nThe key value of children are " << find_node->left->key << " and " << find_node->right->key << endl;
	else
		cout << "Node value: " << find_node->key << "\nNo children" << endl;
	*/
	/*
	binary_tree.display(1);
	binary_tree.display(2);
	binary_tree.display(3);
	*/
	
	binary_tree.display(2);

	binary_tree.delete_node();
	
	binary_tree.display(2);

	
	
	return 0;
}
