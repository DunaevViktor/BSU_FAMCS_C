#include <iostream>
#include <string>
using namespace std;

class geroy
{
protected:
	char name[20];
	char sila[20];
	char health[20];
public:
	geroy()
	{
		char zero[20]="0";
		strcpy(name,zero);
		strcpy(sila,zero);
		strcpy(health,zero);
	}
	geroy(char* _name, char* _sila, char* _health)
	{
		strcpy(name,_name);
		strcpy(sila,_sila);
        strcpy(health,_health);
	}
	void change_name(char* newname)
	{
		strcpy(name,newname);
	}
	void change_sila(char* newsila)
	{
		strcpy(sila,newsila);
	}
	void change_health(char* newhealth)
	{
		strcpy(health,newhealth);
	}
    friend ostream& operator <<(ostream& out, geroy& h);
	virtual ~geroy()
	{
	}
};
ostream& operator << (ostream& out,geroy& h)
	{
		out<<"���: "<<h.name<<endl<<"����: "<<h.sila<<endl<<"�����: "<<h.health<<endl;
		return out;
	}


class magik:public geroy
{
protected:
	char ma[20];
public:
	
	magik(char* _ma,char* _name,char* _sila, char* _health):geroy(_name,_sila,_health)
	{
		strcpy(ma,_ma);
	}
	void change_ma(char* newma)
	{
		strcpy(ma,newma);
	}
	friend ostream& operator << (ostream& out, magik& wh);
	virtual ~magik(){};
};
ostream& operator << (ostream& out, magik&wh)
{
	cout<<"���: "<<wh.name<<endl<<"����: "<<wh.sila<<endl<<"�����: "<<wh.health<<endl;
	cout<<"�����: "<<wh.ma<<endl;
	return out;
}


int main()
{
	setlocale (LC_ALL,".1251");
	char*n=new char[20];
	char*n2=new char[20];
	char*s=new char[20];
	char*l=new char[20];
	char*w=new char[20];
	char*w2=new char[20];
	cout<<"������� ���:"<<endl;
	cin.getline(n,19,'\n');
	cout<<"������� ���������� ����:"<<endl;
	cin.getline(s,19,'\n');
	cout<<"������� ���������� �����:"<<endl;
    cin.getline(l,19,'\n');
	cout<<"����� - ������� �����: "<<endl;
	geroy P1(n,s,l);
	cout<<P1<<endl;
	cout<<"������� ����� ���:"<<endl;
	cin.getline(n2,19,'\n');
	P1.change_name(n2);
    cout<<"����� - ������� �����(����� ���): "<<endl;
	cout<<P1<<endl;

	cout<<"������� ���������� �����:"<<endl;
	cin.getline(w,19,'\n');
	cout<<"����� - ���������� �����: "<<endl;
	magik P2(w,n,s,l);
	cout<<P2<<endl;
	cout<<"������� ����� ���������� �����:"<<endl;
	cin.getline(w2,19,'\n');
	P2.change_ma(w2);
    cout<<"����� - ���������� �����(����� �����): "<<endl;
	cout<<P2<<endl;
	cout<<"������� ����� ���:"<<endl;
	cin.getline(n2,19,'\n');
	P2.change_name(n2);
    cout<<"����� - ���������� �����(����� ���): "<<endl;
	cout<<P2<<endl;
	return 0;
}