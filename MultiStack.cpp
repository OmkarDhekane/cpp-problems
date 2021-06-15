#include<iostream>
#include<string>
#include<fstream>
using namespace std;

class MultiStack{
private:
	int k,n,free;	//free var will store index of free slot in array at which item will be pushed
	int*array;
	int*top;	//array of indices of top element of stacks
	int*next;	//array of indices of next free slot
public:
	MultiStack(int totalStacks,int sizeOfArray);
	bool isEmpty(int stackNumber);
	bool isFull();
	void push(int item,int stackNumber);
	int pop(int stackNumber);
	void display();
};
MultiStack::MultiStack(int totalStacks,int sizeOfArray){
	k = totalStacks;
	n = sizeOfArray;
	free = 0;		//IMP
	array = new int[n];
	next = new int[n];
	top = new int[k];
	for(int i=0;i<k;i++){
		top[i] = -1;
	}
	for(int i=0;i<n;i++){
		next[i] = i+1;
		array[i] = -111;
	}
	next[n-1] = -1;	
}
bool MultiStack::isEmpty(int stackNumber){return (top[stackNumber] == -1);}
bool MultiStack::isFull(){return (free == -1);}

void MultiStack::push(int item,int stackNumber){
	if(isFull()){
		cout << "Stack " << stackNumber <<" is full! cannot insert " << item << "." <<endl;return;
	}
	int i = free;		//store current/first free slot
	free = next[i];	//get next free slot
	
	//update top and next arrays for given stackNumber
	next[i] = top[stackNumber];
	top[stackNumber] = i;
	
	array[i] = item;
}
int MultiStack::pop(int stackNumber){
	int item = INT_MAX;
	if(isEmpty(stackNumber)){
		cout << "Stacks are empty";return item;
	}
	int i = top[stackNumber];
	top[stackNumber] = next[i];
	next[i] = free;
	free = i;
	item = array[i];
	return item;
}
void MultiStack::display(){
	cout << "\nArray of Stack is: ";
	for(int i=0;i<n;i++){
		if(array[i] == -111){
			cout << "_ ";
		}else{
			cout << array[i] << " ";
		}
	}
	cout<<endl;
}

int main()
{
	MultiStack ks(3,10);
	
	cout <<"\nInital array of stack:\n";	
	ks.display();
	
	cout <<"\nInserting to stack 2...\n";	
    ks.push(15, 2);
    ks.push(45, 2);
  	ks.display();
  	
  	cout <<"\nInserting to stack 1...\n";	
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
  	ks.display();
  	
  	
  	cout <<"\nInserting to stack 0...\n";	
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
    ks.push(24, 0);
    ks.push(80, 0);
    ks.push(799, 0);
  	ks.display();
  	
  	cout << "\n\nNow poping...\n";
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
  
	

 return 0;
}

