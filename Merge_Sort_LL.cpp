/*
 * Program: Merge sort a Linked list
 * 
 * Author: Jwala Mohith Girisha
 * 
 */
 
 
#include<iostream>
#include<stdlib.h>
#include<cstddef>

using namespace std;

struct node{
	
	int data;
	struct node* next;
	
}*list1 = NULL;


void print_array(int *ptr, int len);
void create_linkedlist(int *ptr, struct node** list, int len);
void print_linkedlist(struct node* list);

struct node* merge_list(struct node* lista, struct node* listb);
void sort_split(struct node* list, struct node** firstlist, struct node** secondlist);
void merge_sort(struct node** list);


int main(){
	
	cout << "This is a program to merge sort a LL\n\n" << endl;
	
	int n1; 
	int array1[100];
	
	cout << "Enter the number of nodes in the LL: ";
	cin >> n1;
	
	cout << "\nEnter the " << n1 << " data values of nodes\n";
	
	for(int i=0; i<n1 ; i++){
		
		cin >> array1[i];
		
	}
	
			
	create_linkedlist(array1, &list1, n1);
	
	cout << "Linked lists created\n";
	
	cout << "LL to be sorted\n";

	print_linkedlist(list1);
	
	cout << "\n";
	
	cout << "Merging LL......\n";
		
	merge_sort(&list1);	
			
	cout << "Sorted LL\n";
	print_linkedlist(list1);

	return 0;
	
}
 
void merge_sort(struct node** list)
{
  struct node* head = *list;
  struct node* lista;
  struct node* listb;
 
  if ((head == NULL) || (head->next == NULL))
    return;
 
  sort_split(head, &lista, &listb); 
 
  merge_sort(&lista);
  merge_sort(&listb);
 
  *list = merge_list(lista, listb);
}
 

struct node* merge_list(struct node* lista, struct node* listb)
{
  struct node* result = NULL;
 
  if (lista == NULL)
     return(listb);
  else if (listb==NULL)
     return(lista);
 
  if (lista->data <= listb->data)
  {
     result = lista;
     result->next = merge_list(lista->next, listb);
  }
  else
  {
     result = listb;
     result->next = merge_list(lista, listb->next);
  }
  return(result);
}
 
void sort_split(struct node* list, struct node** firstlist, struct node** secondlist)
{
  struct node* twohop;
  struct node* onehop;
  
  if (list==NULL || list->next==NULL)
  {
    *firstlist = list;
    *secondlist = NULL;
  }
  else
  {
    onehop = list;
    twohop = list->next;
 
    while (twohop != NULL)
    {
      twohop = twohop->next;
      if (twohop != NULL)
      {
        onehop = onehop->next;
        twohop = twohop->next;
      }
    }
 
    *firstlist = list;
    *secondlist = onehop->next;
    onehop->next = NULL;
  }
}


//Create Linked List
void create_linkedlist(int *ptr, struct node **list, int len){
	
			struct node* new_node, *current_node;

	int i=0;
	while(i!=len){
		new_node = (struct node*) malloc(sizeof(struct node));
		new_node->data = *(ptr+i);
		new_node->next = NULL;

		if(*list == NULL){
		
			current_node = new_node;
			*list = new_node;
		
		}
		else{
		
			current_node->next = new_node;
			current_node = new_node;
		
		}
		i++;
	}
}

void print_linkedlist(struct node* list){
	
	struct node *new_node;
	new_node=list;
	
	while(new_node!=NULL){
		cout << new_node->data << " ";
		new_node=new_node->next;
   }
}
