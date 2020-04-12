#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Link //��������� ��� �������
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
struct Hod  // ��������� ��� �������� �����
{
	int a,b;// a = x; b = y;
};

class MyQueue // ����� �������
{
	Link *head;
	Link *tail;
public: 
	MyQueue()
	{
				head = 0;
				tail = 0;
	}
	bool IsEmpty() // �������� �� ������ �� �������?
	{
		if (head == 0)
			return true;
		else
			return false;
	}
	bool end(const int m,const int n)  // �������� ��������� �� ����� ���������?
    {
	if (((head->x==0)||(head->x==m-1))||((head->y==0)||(head->y==n-1)))
		return true;
	else
		return false;
    }

	void PushBack(int x, int y)//���������� �� �������
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
	MyQueue(MyQueue &p1) // �������� �����������
	{
		head = tail = 0;
		Link*temp = p1.head;
		while (temp != 0)
		{
			PushBack(temp->x, temp->y);
			temp = temp->next;
		}
	
	
	}
	void PopFront(int &x1, int &y1) // ���� ��� �������� - ��������� �� ������� ������ ������� ���
		                            // ������ ������� ��������� �� ������ �������
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
	virtual~MyQueue() //����������
	{
		int a, b;
		while (!IsEmpty())
			PopFront(a, b);
	}
	MyQueue&operator = (const MyQueue a)//�������� �����
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
void PrintQ(MyQueue& q, ostream & out) // ������� ������ 
{
		int i=0;
		Link *temp;
		temp = q.head;
		while (temp)
		{
			out<< "������� ����� "<<i<<" ";
			out << temp->x << " "<< temp->y << endl;
			temp = temp->next;
			i++;
		}

	}





int main()
{
	setlocale (LC_ALL,".1251");
	Hod d[4];                    
	d[0].a=-1; d[0].b=0;          // ��������� �������� �����
	d[1].a=0; d[1].b=1;
	d[2].a=1; d[2].b=0;
	d[3].a=0; d[3].b=-1;          // C������� �����
	ifstream in ("Labirint.txt"); // ������ ����
	int m,n;                      // m - ������,  n - �������
	in>>m>>n;                     // ������ ���������
	int** Hodi;                   // ������� �����           
	Hodi=new int*[m];             // ��������� ������
		for (int i=0; i<m; i++)
			Hodi[i]=new int[n];
	for(int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			Hodi[i][j]=-1;         // ��������� ������� "-1"
	char** Lab;                    // ������� ���������
	Lab=new char*[m];              // ��������� ������
		for (int i=0; i<m; i++)
			Lab[i]= new char[n];
	
	
     for(int i=0; i<m; i++)
		for (int j=0; j<n; j++)
			in>>Lab[i][j];         // ��������� ������� ��������� �� �����
	 
	MyQueue Proc;                  // ������� �������
	cout<<"��������:"<<endl;
	for(int i=0; i<m; i++)
	 {
		 for (int j=0; j<n; j++)
		 cout<<Lab[i][j];	 // ������� ��������
		 cout<<endl;
	 } 
	int xst,yst; // ���������� ������ ��������
	cout<<"������� �����(�����) ������ ��������?"<<endl;
	cin>>xst>>yst;
	int x,y;
	Hodi[xst][yst]=5; // � ������� ����� ��� ������ "5"
	
	
	Proc.PushBack(xst,yst);
	int nx, ny; // ������� ����������
	do
	{
		Proc.PopFront(x,y);
		for (int i=0; i<4; i++) // ���� ��������� �����
		{
			
			nx=x+d[i].a;
			ny=y+d[i].b;
			if ((Hodi[nx][ny]==-1)&&(Lab[nx][ny]!='x')) // ������� ��� ���������� ����
			{
				Proc.PushBack(nx,ny);
				Hodi[nx][ny]=i;
				
			}
			
		}
		if(Proc.IsEmpty())         // ���� ������ ���
		{
			cout<<"������ ��� :("<<endl;
			return 0;
		}
	
	}
	while (!(Proc.end(m,n)));
    Proc.PopFront(x,y);
	cout<<endl<<" ����� ������ "<< xst<<" "<<yst;
	cout<<endl<<" ����� ������ "<<x<<" "<<y<<endl;
	
	Lab[x][y]='F';
	int num=0; // ������ ��� ����� � ����� F
	while (!((x==xst)&&(y==yst))) // ���� ���������� �������� "."
	{
		int i=Hodi[x][y];
		x=x-d[i].a;
		y=y-d[i].b;
		Lab[x][y]='.';
		num++; //������� �����
	}
	cout<<"���������� ����� �� ������ = "<<num<<endl;
	Lab[x][y]='S';
	cout<<"�������:"<<endl;
	for(int i=0; i<m; i++) // ����� ������ ���������
	 {
		 for (int j=0; j<n; j++)
			cout<<Lab[i][j];	
		 cout<<endl;
	 }
	return 0;
}

