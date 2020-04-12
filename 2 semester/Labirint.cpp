#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Link //Структура для очереди
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
struct Hod  // Структура для описания ходов
{
	int a,b;// a = x; b = y;
};

class MyQueue // Класс очередь
{
	Link *head;
	Link *tail;
public: 
	MyQueue()
	{
				head = 0;
				tail = 0;
	}
	bool IsEmpty() // Проверка не пустой ли лабринт?
	{
		if (head == 0)
			return true;
		else
			return false;
	}
	bool end(const int m,const int n)  // Проверка достигнут ли конец лабиринта?
    {
	if (((head->x==0)||(head->x==m-1))||((head->y==0)||(head->y==n-1)))
		return true;
	else
		return false;
    }

	void PushBack(int x, int y)//Вытолкнуть из очереди
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
	MyQueue(MyQueue &p1) // Оператор копирования
	{
		head = tail = 0;
		Link*temp = p1.head;
		while (temp != 0)
		{
			PushBack(temp->x, temp->y);
			temp = temp->next;
		}
	
	
	}
	void PopFront(int &x1, int &y1) // Есть два варианта - проверять на пустоту внутри функции или
		                            // внутри главной программы до вызова функции
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
	virtual~MyQueue() //Деструктор
	{
		int a, b;
		while (!IsEmpty())
			PopFront(a, b);
	}
	MyQueue&operator = (const MyQueue a)//Оператор равно
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
	friend void PrintQ(MyQueue& q, ostream & out);
	
};
void PrintQ(MyQueue& q, ostream & out) // Функция печати 
{
		int i=0;
		Link *temp;
		temp = q.head;
		while (temp)
		{
			out<< "Элемент номер "<<i<<" ";
			out << temp->x << " "<< temp->y << endl;
			temp = temp->next;
			i++;
		}

	}





int main()
{
	setlocale (LC_ALL,".1251");
	Hod d[4];                    
	d[0].a=-1; d[0].b=0;          // Заполняем струтуру ходов
	d[1].a=0; d[1].b=1;
	d[2].a=1; d[2].b=0;
	d[3].a=0; d[3].b=-1;          // Cмещение точки
	ifstream in ("Labirint.txt"); // Читаем файл
	int m,n;                      // m - строки,  n - столбцы
	in>>m>>n;                     // Размер лабиринта
	int** Hodi;                   // Матрица ходов           
	Hodi=new int*[m];             // Выделение памяти
		for (int i=0; i<m; i++)
			Hodi[i]=new int[n];
	for(int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			Hodi[i][j]=-1;         // Заполняем матрицу "-1"
	char** Lab;                    // Матрица лабиринта
	Lab=new char*[m];              // Выделение памяти
		for (int i=0; i<m; i++)
			Lab[i]= new char[n];
	
	
     for(int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			in>>Lab[i][j];         // Заполняем матрицу лабиринта из файла
	 
	MyQueue Proc;                  // Создаем очередь
	cout<<"Лабиринт:"<<endl;
	for(int i=0; i<m; i++)
	 {
		 for (int j=0; j<n; j++)
		 cout<<Lab[i][j];	 // Выводим лабиринт
		 cout<<endl;
	 } 
	int xst,yst; // Координаты начала маршрута
	cout<<"Введите место(точку) начала маршрута?"<<endl;
	cin>>xst>>yst;
	int x,y;
	Hodi[xst][yst]=5; // В матрице ходов для начала "5"
	
	
	Proc.PushBack(xst,yst);
	int nx, ny; // Текущие координаты
	do
	{
		Proc.PopFront(x,y);
		for (int i=0; i<4; i++) // Цикл возможных ходов
		{
			
			nx=x+d[i].a;
			ny=y+d[i].b;
			if ((Hodi[nx][ny]==-1)&&(Lab[nx][ny]!='x')) // Условие для совершения хода
			{
				Proc.PushBack(nx,ny);
				Hodi[nx][ny]=i;
				
			}
			
		}
		if(Proc.IsEmpty())         // Если выхода нет
		{
			cout<<"Выхода нет :("<<endl;
			return 0;
		}
	
	}
	while (!(Proc.end(m,n)));
    Proc.PopFront(x,y);
	cout<<endl<<" Точка старта "<< xst<<" "<<yst;
	cout<<endl<<" Точка финиша "<<x<<" "<<y<<endl;
	
	Lab[x][y]='F';
	int num=0; // Считая все точки и букву F
	while (!((x==xst)&&(y==yst))) // Цикл заполнения маршрута "."
	{
		int i=Hodi[x][y];
		x=x-d[i].a;
		y=y-d[i].b;
		Lab[x][y]='.';
		num++; //Счетчик ходов
	}
	cout<<"Количество шагов до выхода = "<<num<<endl;
	Lab[x][y]='S';
	cout<<"Маршрут:"<<endl;
	for(int i=0; i<m; i++) // Вывод нового лабиринта
	 {
		 for (int j=0; j<n; j++)
			cout<<Lab[i][j];	
		 cout<<endl;
	 }
	return 0;
}

