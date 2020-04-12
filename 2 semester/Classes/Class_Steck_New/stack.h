/* Пример класса реализующего абстрактный тип 
данных "стек" на списковой структуре */
#include<iostream>
using namespace std;
#ifndef STACK1488  // Директивы кампилятора 
#define STACK1488
class stack       /* Информационная часть храниться 
				  в виде указателей на реальный объект */
{
	struct Link
	{
		void *data;
		Link *next;
		Link (void *dat,Link *nxt);
		virtual ~Link();
	} *head; // head по умолчанию proved - переманная 
	         //Link* head;
	int len; //длинна
	
public:
	stack(); // Пустой стек
	void print()
	{
		Link*temp=head;
		while(temp!=0)
		{
			cout<<*((int*)temp->data)<<" ";
			temp=temp->next;
		}
		cout<<endl;
	}
	stack(int len1)
	{
		head=0;
		len=len1;
	}
	virtual stack::~stack();
	void push (void *dat)
	{
	head = new Link(dat,head); //Выделяем память, инициализируем инфо, даем новый адрес.
	}
	void *pop();
	stack(const stack &r);
	void *pick();
	bool isEmpty()
	{
		if(head==0)
			return true;
		return false;
	}
};
#endif