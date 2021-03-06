#include<iostream>
#include<fstream>
#include<string>
using namespace std;

template <class T>

class BHeap
{
	int n;//kol-vo elementov
    T A[1000];//massiv
public:
BHeap()
	{
		n=0;
		T x;
		//A[0]=maxT(x);
		A[0]=minT(x);
	}
void push(const T &x)
	{
       n++;
	   A[n]=x;
	   int n1=n;
	   while(A[n1/2]>A[n1])
	   {
		   T y=A[n1/2];
		   A[n1/2]=A[n];
		   A[n]=y;
		   n1=n1/2;
	   }
	}

T& top()
	{
		return A[1];
	}

void Hapify(int i)
	{
int k=i;

if((2*i <=n)&&(!(A[2*i]>A[k])))
{
k=2*i;
}

if((2*i+1<=n)&&(!(A[2*i+1]>A[k])))
{
	k=2*i+1;
}
if(i==k)
return;

T y=A[i];
A[i]=A[k];
A[k]=y;
Hapify(k);
	}

void pop()
{
	A[1]=A[n];
	n--;
	Hapify(1);
}
};

string maxT(string s)
{
	string s1("z");
	return s1;
}

string minT(string s)
{
	string s1;
	return s1;
}

int main()
{
	setlocale(LC_ALL,".1251");
	int c = 0;
    ifstream is("in.txt");
	BHeap <string>BH;
    string word;
	cout<<"Дерево: "<<endl;
	while(!is.eof())
	{
		is >> word;
		if(is.bad())
			break;
		c++;
		BH.push(word);
	}
for(int i=0;i<c;i++)
{
	cout<<BH.top()<<" ";
	BH.pop();
}
cout<<endl;

	return 0;
}