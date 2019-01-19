#include <iostream>
using namespace std;
class circle{
	public:
		//number
		int number;
		//pointer to the nxt circle
		circle * nxt;
		circle * prev;
		//constructor that makes the pointer part of the circle to null
		circle();
};
circle::circle(){
	nxt =NULL;
	prev = NULL;
}
//class linked list
class linkedlist{
	public:
		//head  and circle inside linked list
		//head and tails are circle type pointers
		circle * head;
		circle * tail;
		//default constructor
		linkedlist();
		//circles are linked with each other so we have to decide how they get linked
		//inserting a circle
		void insert(int num);
		//inserting at a point
		void insertat(int pos, int value);
		//delete at end
		void delet();
		//delete at a position
		void deleteat(int pos);
		//count numer of circle in lnked list
		void count();
		//display
		void display();
	
};
linkedlist::linkedlist(){
	head= NULL;
	tail= NULL;
}
void linkedlist::insert(int num){
	//if 1st circle is added the
	circle * tempo = new circle;
	//insert value in teh circle
	tempo->number=num;
	//1st circle only 
	if (head == NULL)
		head=tempo;
	//other circle
	else
	{
		tail -> nxt = tempo;
		tempo -> prev = tail;
	}
	tail = tempo;
	}
	
void linkedlist::insertat(int pos, int value){
	// Create a circle
        circle * temp = new circle;
        temp -> number = value;
        // Reach the place before the pos
        circle * current = head;
        int i =1;
	// Update the code for 1st position
	if (pos==1){
		temp -> nxt = current;
		current -> prev = temp;
		head = temp;
	}	
	else{
		int i =1;
		while(i < pos-1){
			if(current -> nxt == NULL){
				cout<<"Linked List does not have that many elements"<<endl;
				break;
			}
			else{
			i++;
			current = current->nxt;
			}
		}
		if(current -> nxt != NULL){
		// Moving ptrs like magic ! if not head
		temp->nxt = current->nxt;
		current->nxt = temp;
		temp -> prev = current;
		temp -> nxt -> prev = temp;
		}
	}
       }

    // Deletion of last element
void linkedlist::delet(){
        // store the tail in tempo
        circle * tempo = tail;
        // before tail has to point to null
        circle * current = head;
        while(current->nxt != tail){
            current = current->nxt;
        }
        current->nxt = NULL; 

        // update tail
        tail = current;
        // delete tempo
         delete tempo;
    }
void linkedlist::deleteat(int pos){
		//storing data of the head
		circle * current = head ;
		//for 1st position
		if(pos==1){
			head=current->nxt;
			current -> nxt -> prev = NULL;
			delete current;
		}
		else{
			//finding twh position to delete
			int i=1;
			while(i<pos-1)
				{
				if(current -> nxt == NULL){
					cout<<"Linked List does not have that many elements"<<endl;
					break;
				}
				else{
				i++;
				current  = current-> nxt;
				}
			}
			if(current -> nxt != NULL){
				//storing the position to delete
				circle * del = current -> nxt;
				//pointing previous circle to nxt of the del(that we want to delete circle)
				current -> nxt = del -> nxt;
				current -> nxt -> prev = current;
				delete del;
			}
		}	
}
//count
void linkedlist::count(){
	circle * current = head;
	int count=0;
        while(current != NULL){
            count++;
            current = current->nxt;
        }
        cout <<"Linked list have "<<count<<" elements"<< endl;
    }
// Display
void linkedlist::display(){
	circle * current = head;
	circle * last = tail;
	cout<<"print in order:"<<endl;
        while(current != NULL){
            cout << current->number << "->";
            current = current->nxt;
        }
        cout <<" NULL"<< endl;
	cout<<"print in reverse order"<<endl;
	while(last != NULL){
		cout<<last->number<<"->";
		last=last->prev;
	}
	cout<<"NULL"<<endl;   
    }

int main(){
	linkedlist l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.insert(4);
    	l.insert(5);
    	l.display();
   	l.deleteat(3);
    	l.display();
    	l.insertat(3,7);
    	l.display();
	l.delet();
    	l.display();
    	l.count();
	l.insertat(1,8);
	l.display();
	return 0;
}
