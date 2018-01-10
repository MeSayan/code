#include <iostream>

using namespace std;

struct Node {
	int data;
	struct Node *prev, *next;
};

void print_list(Node **start) {
	Node *temp = *start;
	while ( temp != nullptr ) {
		cout << temp->data << " ";
		temp = temp->next;
	}
}

Node * create_node(int val) {
	Node *temp = new Node;
	temp->data = val;
	temp->prev = temp->next = nullptr;
	return temp;
}

void insert_beg(Node **start,int val) {
	Node * temp = create_node(val);
	temp->next = (*start)->next;
	temp->prev = (*start);
	(*start)->next = temp;
}

void swap_nodes(Node **i, Node **j) {
	if( (*i) == (*j));
	else if ( (*i)->next == (*j)) {
		cout << (*i)->data << (*j)->data << endl;
		// I and J are adjacent
		cout << (*j)->data << " ";
		(*i)->next = (*j)->next;
		cout << (*j)->data << " ";
		cout << (*i)->next->data << " ";
		
		
		(*j)->prev = (*i)->prev;
		cout << (*j)->prev->data << " ";
		
		
		(*j)->next = (*i);
		cout << (*j)->next->data << " ";
		
		
		
		(*i)->prev = (*j);
		cout << (*j)->data << " ";
	}
	else ;
	
}
	

int main() {

	// Start and end are dummy nodes
	Node * start = create_node(-1);
	Node * end = create_node(-1);
	
	start->next = end;
	end->prev = start;
	
	insert_beg(&start,34);
	insert_beg(&start,45);
	insert_beg(&start,41);
	insert_beg(&start,32);
	insert_beg(&start,67);
	
	print_list(&start);
	
	
	swap_nodes(&(start->next),&(start->next->next));
	
	return 0;
}
