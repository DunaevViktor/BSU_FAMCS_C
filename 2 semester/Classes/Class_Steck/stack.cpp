/* Пример класса реализующего абстрактный тип 
данных "стек" на списковой структуре */
#include "stack.h"

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
	head=0;
}
/*void stack::Push(void *dat)
{
	head = new Link(dat,head); //Выделяем память, инициализируем инфо, даем новый адрес.
} */
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


