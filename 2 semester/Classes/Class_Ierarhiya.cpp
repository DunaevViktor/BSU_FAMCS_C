#include<iostream>
using namespace std;

template<class T>
struct node
{
	T info;
	node *next;

	node(T inf1)
	{
		info = inf1;
		next = 0;
	}

	node(T inf1, node*nex1)
	{
		info = inf1;
		next = nex1;
	}
};
template<class T>
class  AbstrStack
{

public:
	virtual bool isEmpty() = 0;
	virtual bool isFull() = 0;
	virtual T peek() = 0;
	virtual T pop() = 0;
	virtual void push(T &x) = 0;
};
template<class T>
class StackLink : public AbstrStack<T>
{
public:
	node<T>*top;
public:
	StackLink()
	{ 
		top = 0; 
	}
	bool isEmpty()
	{ 
		return top == 0 ? true : false; 
	}
	bool isFull()
	{ 
		return false; 
	}
	T peek() 
	{ 
		return top->info; 
	}
	void push(T&x)
	{
		node<T> *N = new node<T>(x, top);
		top = N;
	}
	T pop()
	{
		node<T>*N = top;
		top = top->next;
		T inf1 = N->info;
		delete N;
		return inf1;
	}
	virtual ~StackLink()
	{
		while (!isEmpty()) pop();
	}
};

template<class T>
class StackArray :public AbstrStack<T>
{
protected:
	T stack[100];
	int top;
public:
	StackArray() :top(0)
	{
	}
	bool isEmpty()
	{
		return top == 0 ? true : false;
	}
	bool isFull()
	{
		return top == 100 ? true : false;
	}
	T peek()
	{
		return stack[top-1];
	}
	void push(T&x)
	{
		if (!(top < 100))
		{
			cout << "Too many push!" << endl;
			return;
		}
		stack[top++] = x;
	}
	T pop()
	{
		if ((top<=0))
		{
			cout << "Too many pop!" << endl;
			return NULL;
		}
		else
		{
			top--;
		}
	}
	virtual ~StackArray()
	{
		delete[]stack;
	}
};

int main()
{

	AbstrStack<int>* P = new StackLink<int>;

	int n;
	int temp;
	cout << "Input koluchestvo elementov Steka_Link:" << endl;
	cin >> n;
	cout << "Vvedite Stek_Link:" << endl;
	for (int i = 0; i < n; i++)
	{
		if (!P->isFull())
		{
			cin >> temp;
			P->push(temp);
		}
		else break;
	}
	if (!P->isEmpty())
		cout << "Peek for last element:" << endl;
	cout << P->peek() << endl << endl;;



		AbstrStack<double>* P1 = new StackArray<double>;

		int n1;
		int temp1;
		double tmp2;
		cout << "Input koluchestvo elementov Steka_Array:" << endl;
		cin >> n1;
		cout << "Vvedite Stek_Array:" << endl;
		for (int i = 0; i < n1; i++)
		{
			if (!P1->isFull())
			{
				cin >> tmp2;
				P1->push(tmp2);
			}
			else break;
		}
		while (!P1->isEmpty())
		{
			cout << "Peek for last element:" << endl;
			cout << P1->peek() << endl;
			P1->pop();
		}
	return 0;
}

