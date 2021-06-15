#include<iostream>
#include<string>
#include<fstream>
using namespace std;
class Queue{
private:
//	int front,rear,size;
	int* arr;
public:
	int front,rear,size;
	Queue(int Size);
	bool isFull();
	bool isEmpty();
	void enqueue(int data);
	int dequeue();
	void display();
};
bool Queue::isEmpty(){
	return (front == -1 || rear == -1);
}
bool Queue::isFull(){
	return ((rear == size-1 && front == 0) || (rear == (front-1)%(size-1)));
}
Queue::Queue(int Size){
	front = rear = -1;
	arr = new int[Size];
	size = Size;
}
void Queue::enqueue(int data){
	if(isFull()){	//check if q is full
		cout << "\nQueue is full!"<<endl;
	}
	else if(isEmpty())		//if q is empty
	{
		front = rear = 0;
		arr[rear] = data;
	}
	else if(rear == size-1 && front !=0){	// if q not empty and front is shifted to other index
		rear = 0;
		arr[rear] = data;
	}else{
		rear++;
		arr[rear] = data;
	}
}
int Queue::dequeue(){
	if(isEmpty()){
		cout << "\nQueue is empty!"<<endl;
		return INT_MIN;
	}
	int data = arr[front];
	arr[front] = 9999;
	if(front  == rear){	//only one element
		front  = rear  = -1;
	}
	else if(front == size-1){	
		front = 0;
	}else{
		front++;
	}
	return data;
}
void Queue::display(){
	if(isEmpty()){
		cout << "\nQueue is empty now!!!"<<endl;return;
	}
	cout << "\nQueue elements are: ";
	if(rear >= front){
		for(int i=front;i<=rear;i++){
			cout << arr[i] << " ";
		}
	}else{
		for(int i=front;i<size;i++){
			cout << arr[i] << " ";
		}
		for(int i=0;i<=rear;i++){
			cout << arr[i] << " ";
		}
	}
	
}


int main()
{
	Queue q(5);
	 
	q.enqueue(14);
	q.enqueue(22);
	q.enqueue(13);
	q.enqueue(-6);
	
	q.display();
	
	printf("\nDeleted value = %d", q.dequeue());
    printf("\nDeleted value = %d", q.dequeue());
    
	q.display();
 
    q.enqueue(9);
    q.enqueue(20);
    q.enqueue(5);
 
    q.display();
 
 
    q.enqueue(20);
 return 0;
}

