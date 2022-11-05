#include <iostream>
#include "queue.h"

using namespace std;

int main(int argc, char** argv) {
	Queue<int> q;
	q.enQueue(5,'I');
	q.enQueue(15,'D');
	q.enQueue(25,'I');
	q.enQueue(45,'D');
	q.enQueue(55,'I');
	q.enQueue(65,'D');
	q.enQueue(75,'I');
	q.imprimir_queue('I');
	
	cout<<endl;
	cout<<q.deQueue('D')<<endl;	
	q.imprimir_queue('I');
	
	cout<<endl;
	cout<<q.deQueue('I')<<endl;	
	q.imprimir_queue('D');
	
	cout<<endl;
	cout<<q.deQueue('I')<<endl;	
	q.imprimir_queue('D');
	
	cout<<endl;
	cout<<q.deQueue('D')<<endl;	
	q.imprimir_queue('I');
	
	return 0;
}	