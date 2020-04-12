/* Пример класса реализующего абстрактный тип 
данных "стек" на списковой структуре */
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
	} *head;   // head по умолчанию proved - переманная 

public:
	stack(); // Пустой стек
	virtual stack::~stack();
	void push (void *dat)
	{
	head = new Link(dat,head); //Выделяем память, инициализируем инфо, даем новый адрес.
	}
	void *pop();
	void *pick();
	bool isEmpty()
	{
		if(head==0)
			return true;
		return false;
	}
};
#endif