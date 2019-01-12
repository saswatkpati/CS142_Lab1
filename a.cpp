//Singly Linked List using C++.
//Adding the library
#include <iostream>
using namespace std;

class Node{
	public:
	//Data
	int data;
	//pointer to the next node
	Node*next;
	//construct that makes the ptr to null
	Node (){
		next=NULL;
	}
};

class LinkedList{
	//Head+circles inside linked with each other
	public:
	//Head --> circle type ptr
	Node * head;
	Node * tail;

	//construct
	LinkedList(){
		head = NULL;
		tail = NULL;
	}
	//circles inside linked with each other
	//Q1.insert(int data) - Adds a new element to the end of the linked list.
	void Insert(int value){
		//1st node has to be addded
		Node * temp = new Node;
		//Insert value in the node
		temp->data = value;	
		//1st node only
		if (head == NULL)
			head = temp;
		//any other node only
		else{
			tail->next = temp;
		}
			tail = temp;
		}

	//Q2.insertAt(int pos, int data) - It includes the position at which the insertion happens. Positioning starts with 1.
	void insertAt(int pos, int value){
		// Reach the place before the pos
		Node * current = head;
		int i =1;
		
		// Create a node
		Node * temp = new Node;
		temp -> data = value;

		//if pos is 1. we need to take the current 1 to 2 so that 1 will be now empty
		if (pos ==1){
			temp->next = head;
			head = temp;		
		}
		else {
			while(i < pos-1){
			    i++;
			    current = current->next;
			}
		
		
		// Moving ptrs like magic ! if not head //Don't want to change that statement 
		temp->next = current->next;
		current->next = temp;
		}
		
		}

	//Q3.Deletion of last element
	void deletee (){
		//store the tail in temp
		Node * temp = tail;
		//before tail has to point to null
		Node * current = head;
		//while loop to reach the last position		
		while(current ->next != tail){
            		current = current->next;
        	}
			current->next = NULL; 

	        // update the tail
	        tail = current;
	        // now delete temp
	        delete temp;
		}
	//Q4.deleteAt(int pos) - Deletes the element(or node) at the position pos
	void deleteAt (int posn){
		int i =1;
		Node * current = head;
		if (posn==1){
			head =current ->next;
			delete current;
		} 
		else {
			//reaching the position
			while(i< posn-1){
				i++;
            			current = current->next;
		}
		Node * temp;
		//make the position's node = temp
		temp = current ->next;
		//temp ra next current ra next sange saman haba darkar 
		current ->next = temp ->next;
		delete temp;
        	}
	}
	//Display
	void display(){
		Node * current = head;
		while (current != NULL){
			cout << current->data << "->";
			current = current -> next;
		}
	cout << "NULL" <<endl;
}
	};

int main() {

	LinkedList l1;
	l1.Insert(1);
	l1.Insert(2);
	l1.Insert(3);
	l1.Insert(4);
	l1.display();
		
	cout << "Where do you need to insert a node?" << endl;
	int a,b;
	cin >> a;
	cout << "What value to assign in the node?" << endl;
	cin >> b;
	l1.insertAt(a,b);

	l1.display();
	cout << "Now Deleting the last element" <<endl; 
	l1.deletee();
	l1.display();
	
	cout << "Where do you need to delete a node(enter a value between 1 to 4)?" << endl;
	int x;
	cin >> x;

	l1.deleteAt(x);
	l1.display();
return 0;
}

//Sir if you are reading this, I highly doubt that you are, I could not figure out to count the linked list.
