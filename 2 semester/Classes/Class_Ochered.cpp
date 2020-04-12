#include <iostream>
using namespace std;
struct Link
{
	int x, y;
	Link *next;
	Link(int x1, int y1, Link *next1)
	{
		x = x1;
		y = y1;
		next = next1;
	}
	Link(int x2, int y2)
	{
		x = x2; y = y2;
		next = 0;
	}
};

class MyQueue
{
	Link *head;
	Link *tail;
	public: MyQueue()
	{
				head = 0;
				tail = 0;
	}
	bool IsEmpty()
	{
		if (head == 0)
			return true;
		else
			return false;
	}
	void PushBack(int x, int y)
	{
		Link *temp;
		if (!IsEmpty())
		{
			temp = new Link(x, y);
			temp->next = 0;
			tail->next = temp;
			tail = temp;
		}
		else
		{
			temp = new Link(x, y, 0);
			head = temp;
			tail = temp;
		}

	}
	MyQueue(MyQueue &p1)
	{
		head = tail = 0;
		Link*temp = p1.head;
		while (temp != 0)
		{
			PushBack(temp->x, temp->y);
			temp = temp->next;
		}
	
	
	}
	void PopFront(int &x1, int &y1) //есть два варианта - проверять на пустоту внутри функции или внутри главной программы до вызова функции
	{
		if (!IsEmpty())
		{
			x1 = head->x;
			y1 = head->y;
			Link *temp = head;
			head = temp->next;
			delete temp;
			if (head == 0)
				tail = 0;

		}
	}
	virtual~MyQueue()
	{
		int a, b;
		while (!IsEmpty())
			PopFront(a, b);
	}
	MyQueue&operator = (const MyQueue a)
	{
		if (this != &a)
		{
			int a, b;
			while (!IsEmpty())
				PopFront(a, b);
		}
		Link *temp = a.head;
		while (temp != 0)
		{
			PushBack(temp->x, temp->y);
			temp = temp->next;

		}
		return *this;

	
	}
	friend void PrintQ(MyQueue& q, ostream & out)
	{
		Link *temp;
		temp = q.head;
		while (temp)
		{
			out << temp->x << " "<< temp->y << endl;
			temp = temp->next;
		}

	}


};


void main()
{
	int a, b, c, d;
	cout << "Vvedite koordinati pervoy to4ki " << endl;
	cin >> a >> b;
	cout << "Vvedite koordinati vtoroy to4ki " << endl;
	cin >> c >> d;
	cout << "----------" << endl;
	MyQueue q1;
	q1.PushBack(a, b);
	q1.PushBack(c, d);
	cout << "Koordinati to4ek " << endl;
	PrintQ(q1, cout);
	/*MyQueue q2(q1);
	PrintQ(q2, cout);
	int x0, y0;
	{
		q1.PopFront(x0, y0);
		PrintQ(q1, cout);
	}
	*/
	//cin >> a;
	system("pause");
}

