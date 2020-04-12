/* ѕример класса реализующего абстрактный тип 
данных "стек" на списковой структуре */
#include "stack.h"
#include<cstring>

stack::Link::Link (void *dat,Link *nxt)
{
	data=dat;
	next=nxt;
}
stack::Link::~Link()
{
}
stack::stack()
{
	len=4;
	head=0;
}
void *stack::pick()
{
	return head->data;
}
void *stack::pop()
{
	void *res = head->data;
	Link *t = head;
	head = head->next;
	delete t;
	return res;
}
stack::~stack()
{
	while (!isEmpty())
		pop();
}
stack::stack(const stack &r)
{
	stack temp(r.len);
	

	Link *t=r.head;
	while(t!=0)
	{
		temp.push(t->data); 
		t=t->next;
	}
	//temp.print();


	head=0;
	len=r.len;
	while(!temp.isEmpty())
	{
		void *d=temp.pop();
		char *x=new char[len];
		memcpy(x,(char*)d,len);
		push((void*)x);
	}
}




