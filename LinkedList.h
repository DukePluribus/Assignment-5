
#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
using namespace std;
template <class T>
struct note{
	T data;
	note* next;
};

template <class T>
class LinkedList{
	private:
		LinkedList(const LinkedList&)=delete; //copy constructor

	protected:
	//Keeps track of number of items in the list
		int count;
	//Pointers to the first and last note in the list
		note<T> *head, *last;
	public:
		LinkedList();
		bool isEmpty();
		int length();
		T front();
		T back();
		void inserFirst(T&);
		void inserLast(T&);
		T search(T&);
		void deleteNote(T&);
		void destroylist();
		LinkedList<T>& operator=(LinkedList<T>&);
		template <class U>
		friend ostream& operator<<(ostream& os, LinkedList<U>& list);
		~LinkedList();
};
//Constructor
template <class T>
LinkedList<T>::LinkedList(){
     head = last = NULL;
     count = 0;
}
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~Set of methods to return information about structure of the list~~~
template <class T>
bool LinkedList<T>::isEmpty(){
	return head==NULL;
}
template <class T>
int LinkedList<T>::length(){
	return count;
}
//Pointer to the front of the list
template <class T>
T LinkedList<T>::front(){
	return head->data;
}
//Pointer to the back of the list
template <class T>
T LinkedList<T>::back(){
	return last->data;
}

//~~~Insert Data Methods~~~
//Insert data at beginning of list
template <class T>
void LinkedList<T>::inserFirst(T& item){
	note<T> *temp = new note<T>;
	temp->data = item;
	temp->next = head;
	head = temp;
	count++;
	if(last==NULL) last = temp;
}
//Insert data at end of list
template <class T>
void LinkedList<T>::inserLast(T& item){
	note<T> *newnote = new note<T>;
	newnote->data = item;
	newnote->next = NULL;
	if(head==NULL){
		head = last = newnote;
	}else{
		last->next = newnote;
		last = newnote;
	}
	count++;
}

//note deletion method
template <class T>
void LinkedList<T>::deleteNote(T& item){
	if(head == NULL)
		throw "EmptyListError";
	else{
		if(head->data == item){
			note<T>* p = head;
			head = head->next;
			delete p;
			count--;
			if(head==NULL) last = NULL;
		}else{
			note<T>* p = head;
			note<T>* q = p->next;
			while(q!=NULL && q->data != item){
				p = q;
				q = q->next;
			}
			if(q!=NULL){
				p->next = q->next;
				count--;
				if(last == q) last = p;
				delete q;
			}
		}
	}
}
//List destructor, points the head to the next item in the list, then deletes the note
template <class T>
void LinkedList<T>::destroylist(){
	note<T> *p;
	while(head != NULL){
		p = head;
		head = head->next;
		delete p;
	}
	last = NULL;
	count = 0;
}
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T>& list){
	if(this!= &list){
		copylist(list);
	}
	return *this;
}


//ostream overload, prints out each piece of data in the list
template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list){
	note<T> *p = list.head;
	while(p!= NULL){
		os<<p->data<<" "<<endl;
		p = p->next;
	}
	return os;
}
//Destructor, just calls the destroylist() method
template <class T>
LinkedList<T>::~LinkedList(){
	destroylist();
}

template <class T>
T LinkedList<T>::search(T& data){
	if(head == NULL)
		throw "EmptyListError";
	else{
		if(head->data == data){
			return head->data;
		}else{
			note<T>* p = head;
			note<T>* q = p->next;
			while(q!=NULL && q->data != data){
				p = q;
				q = q->next;
			}
			if(q!=NULL){
				return q->data;
			}
		}
	}
}

#endif /* LINKEDLIST_H_ */
