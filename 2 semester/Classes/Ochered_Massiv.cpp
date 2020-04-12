#include<iostream>
using namespace std;
struct QFull{};
struct QEmpty{};
class QIterator;
class ArrayQuete
{
	int size;
	int *p;
	int head;
	int tail;
	int n;
public:
	void print()
	{
		cout<<"massive: ";
		for (int i=0; i<size; i++)
			cout<<p[i]<<" ";
		cout<<endl;
	}
	ArrayQuete(int s1)
	{
		size=s1;
		p=new int[size];
		head=-1;
		tail=0;
		n=0;
	}
	ArrayQuete(ArrayQuete &q)
	{
		size=q.size;
		p=new int[size];
		head=q.head;
		tail=q.tail;
		n=q.n;
		for(int i=0;i<size;i++)
		{
			p[i]=q.p[i];
		}
	}
~ArrayQuete()
{
	delete []p;
}
void push_back(int x)
{
	if(n<size)
	{
		p[tail]=x;
		if(n==0)
		   head=tail;
		tail=(tail+1)%size;
		n++;//&&
	}
	else
		throw QFull();
	
}
void pop_front(int &x)
{
	if(n!=0)
	{
		x=p[head];
		n--;
		if(n==0)
		{
			head=-1;
			tail=0;
		}
		else
		head=(head+1)%size;
	}
	else
	throw QEmpty();
}
friend QIterator;
};
class QIterator
{
	ArrayQuete &a;
	int pos;
	QIterator();
    int num;
public:
	QIterator(ArrayQuete &q):a(q)
	{
		pos=a.head;
		num=0;//a
	}
	bool inRange()
	{
		if(num<a.n)
			return true;
		else
			return false;
	}
	void Reset()
	{
		pos=a.head;
		num=0;
	}
	int &operator *()
	{
		return a.p[pos];
	}
	void operator ++()
	{
		pos=(pos+1)%a.size;
		num++;
	}
	void operator ++(int)
	{
        pos=(pos+1)%a.size;
		num++;
	}

};
int main ()
{
	ArrayQuete q(3);
	QIterator it(q);
	int k;
	try
	{
		q.push_back(0);
// q.print();
//		q.pop_front(k);
//q.print();
//		cout<<k<<endl;
		q.push_back(2);
//q.print();
		//q.pop_front(k);
		//cout<<k<<endl;
		for (int i=2;i<7;i++)
		{
			it.Reset();
			while(it.inRange())
			{
				cout<<*it<<" ";
				++it;
			}
			cout<<endl;
			q.push_back(i*2);
//			q.push_back(i*2+1);
//q.print();
			q.pop_front(k);
			q.pop_front(k);
//q.print();
		}
	}
	catch(QFull)
	{
		cout<<"Full"<<endl;
	}
	catch(QEmpty)
	{
		cout<<"Emply"<<endl;
	}
	return 0;
}





















