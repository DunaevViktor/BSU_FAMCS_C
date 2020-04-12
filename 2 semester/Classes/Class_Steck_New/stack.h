/* ������ ������ ������������ ����������� ��� 
������ "����" �� ��������� ��������� */
#include<iostream>
using namespace std;
#ifndef STACK1488  // ��������� ����������� 
#define STACK1488
class stack       /* �������������� ����� ��������� 
				  � ���� ���������� �� �������� ������ */
{
	struct Link
	{
		void *data;
		Link *next;
		Link (void *dat,Link *nxt);
		virtual ~Link();
	} *head; // head �� ��������� proved - ���������� 
	         //Link* head;
	int len; //������
	
public:
	stack(); // ������ ����
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
	head = new Link(dat,head); //�������� ������, �������������� ����, ���� ����� �����.
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