#include<stdio.h>
#include<stdlib.h>
#include<time.h>
struct node{
	int data;
	struct node* next;
};

typedef struct node Node;

Node* create_node(Node* head, int data){
	Node* node = malloc(sizeof(Node));
	node->data = data;

	if(head == NULL){
		head = node;
		node->next = NULL;
	}else{
		node->next = head;
		head = node;
	}

	return head;
}

Node* add_node_after(Node* head, int after_data, int data){
	Node* curr_node = head;
	while(curr_node != NULL){
		if(curr_node->data == after_data){
			Node* node = malloc(sizeof(Node));
			node->data = data;
			
			node->next = curr_node->next;
			curr_node->next = node;
			break;
		}
		curr_node = curr_node->next;
	}
	return head;
}

void print_list(Node* head){
	Node* curr_node = head;
	while(curr_node != NULL){
		printf("%d ", curr_node->data); // arr[i]
		curr_node = curr_node->next; // i = i + 1
	}
	printf("\n");
}

void delete_list(Node* head){
	Node* curr_node = head;
	while(curr_node != NULL){
		head = head->next;
		free(curr_node);
		curr_node = head;
	}	
}

int main(){
	Node* head = NULL;
	head = create_node(head, 5);
	head = create_node(head, 3);
	head = create_node(head, 7);
	head = create_node(head, 9);
	print_list(head);
	head = add_node_after(head, 3, 8);
	print_list(head);
	delete_list(head);
    sleep(6000);


	return 0;
}
