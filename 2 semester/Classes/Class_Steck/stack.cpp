/* ������ ������ ������������ ����������� ��� 
������ "����" �� ��������� ��������� */
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
	head = new Link(dat,head); //�������� ������, �������������� ����, ���� ����� �����.
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


