#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node * next;
} node;

node *headA, *tailA;
node *headB, *tailB;

node * new_node(int val) {
	node *temp = (node *)malloc(sizeof(node));
	temp->data = val;
	temp->next = NULL;
	return temp;
}

void init_list(int init_val) {
	node * tempA = new_node(init_val);
	node * tempB = new_node(init_val);
	headB = tailB = tempB;
	headA = tailA = tempA;
}

void display_list(node **head) {
	node *temp = *(head);
	while( temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void delete_last(node **head) {
	node *temp = *(head);
	while( temp->next->next != NULL ) {
		temp = temp->next;
	}
	free(temp->next->next);
	temp->next = NULL;
}



void sort_list(node **head) {
	node *i, *j, *p;
	int temp,max;
	
	i = *(head);
	
	while( i != NULL && i->next != NULL ) {
		j = i;
		max = i->data;
		while( j != NULL && j->next != NULL ) {
			if( j->next->data > max ) {
				p = j->next;
				max = p->data;
			}
			j = j->next;
		}
		
		// swap i and p
		temp = p->data;
		p->data = i->data;
		i->data = temp;
		
		// Increment i
		i = i->next;
		
	}
}



void insert_beg(node **head, int val) {
	node *temp = new_node(val);
	temp->next = *(head);
	*(head) = temp;
}

void insert_end(node **tail, int val) {
	node * temp = new_node(val);
	(*tail)->next = temp;
	(*tail) = temp;
}

void remove_duplicates(node **head) {
	node *i,*j,*temp;
	
	i = *(head);
	while( i != NULL && i->next != NULL ) {
		j = i;
		while( j != NULL && j->next != NULL ) {
			if( j->next->data == i->data) {
				temp = j->next;
				j->next = temp->next;
				free(temp);
			}
			j = j->next;
		}
		i = i->next;
	}	
}


void merge(node **headA, node **headB) {
	//Merge A into B
	node *ptrA = *headA;
	node *ptrB = *headB;
	node *temp;
	while( ptrB != NULL && ptrA != NULL ) {
		temp = ptrA->next;
		ptrA->next = ptrB->next;
		ptrB->next = ptrA;
		ptrB = ptrA->next;
		ptrA = temp;
	}
}
  				

int main() {
	init_list(0);
	
	insert_end(&tailA,6);
	insert_end(&tailA,7);
	insert_end(&tailA,8);
	insert_end(&tailA,9);
	insert_end(&tailA,10);
	
	insert_end(&tailB,1);
	insert_end(&tailB,2);
	insert_end(&tailB,3);
	insert_end(&tailB,4);
	insert_end(&tailB,5);
	
	display_list(&headA);
	display_list(&headB);
	
	merge(&headA,&headB);
	display_list(&headB);
	
	sort_list(&headB);
	display_list(&headB);
	
	remove_duplicates(&headB);
	display_list(&headB);
	
	return 0;
}
