/* ������ ������ ������������ ����������� ��� 
������ "����" �� ��������� ��������� */
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
	} *head;   // head �� ��������� proved - ���������� 

public:
	stack(); // ������ ����
	virtual stack::~stack();
	void push (void *dat)
	{
	head = new Link(dat,head); //�������� ������, �������������� ����, ���� ����� �����.
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