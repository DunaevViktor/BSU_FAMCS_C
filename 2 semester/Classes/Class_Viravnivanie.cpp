/*����������� ��������� �������������� ������, ������� ��������� � ��������� �����.
��������� ������ ������ � ������� ��� �����, � ������� ��������� �����, 
� ����� ��������� � ������������ ������ ������.
����� ������ ���� �������������� ��������� �������:
	- ������ ����� ������ ��������� � �������� ������� ������;
	- ������� ���� �� �����������;
	- ��� ������������ �����, ����� ������� ����������� �������������� �������;
    - ��������� ������ ������ ������� � ������ ����;
	- ����� �������, ��� ������������ ����� ������� �������� " ";
	- ���� ��������� ���������� ����� �����. */
#include<iostream>
#include<fstream>
using namespace std;
//�������,������� ��������� ������ �� ������ ����
int tokens(char* str,char** mas)
{
	char raz[]=" \n";//�����������
    mas[0]=strtok(str,raz);
	int index=1;
	while(!(mas[index]= strtok(0,raz))==0)
	{
		index++;
	}
  return index;
}
//�������,������� ����� �����,����������� ��� � ������� �� �����(� ����)
//������-�����,���������� ��������,����� ������
void alignment(char* str,int len,ostream &out)
{
	int ob=0;//kol uze napisanih slov
	int sumlen=0;//����� ������ ���� � ������(��� ��������)
	int num;//����� ���������� ���� ���� � ������
    int countw;//������� ��� ����
	int counts;//������� ��� ��������
	int ost;//������ �������,������� �������� ���������������
	char** words=new char*[50*20];//������ ���� ������(��� ����������),�� ����� 50 ���� � ������, � 20 ����� � ������
	string spaces("                    ");//������ ��������(20 ����)
    string res;//�������������� ������ 

	num=tokens(str,words);
	int tmp=0;//����� ����� � ������ ��������� ������

do
	{
	//����� �������� ����� 
int	countw2=0;//��� ���� � ������� ������
	while((countw2+tmp<num )&&((sumlen+countw2+tmp-1+strlen(words[countw2+tmp]))<len)) //���� ������ ������ ������ ��������
	{
		sumlen+=strlen(words[countw2+tmp]);//��������� ����� temp+countw
		if (tmp+countw2<num)
			countw2++;//������������ ����� , ������� �� ������ �������� �� ������
		else 
			break;
	}
	if (countw2 == 0)
	{
		break;
	}
	
	//������ ��� ���� ������� ����� ������� , ������ -1 ������� 
	int ost=len-sumlen-(countw2-1); //temp+countw //strlen(words[countw])-
//������� ������ ���� ���� � ����� ���������� �������� , �������� �������
//c-������ ������������ ��������
//o-���������� ���������� � ������� ������������� �� ������ �������
	int c,o;
	if (countw2 > 1)
	{
		c = ost / (countw2 - 1);
		o = ost % (countw2- 1);
	}
	else
	{
		c = ost;//���� ������
		o = 0;//������ �� ���������
	}
int tmp2=0;//?
tmp2=tmp;
string s1(spaces.substr(0,1+c));
for(int i=0;i<countw2-1;i++) //i ���������� ����������� ���� //-1
{
	res+=(words[tmp2++]);
	res+=s1;//�������
	if(i<o)
		res+=" ";//��� �������
}
res+=(words[tmp2++]);
//ob=tmp2;
//res+=words[tmp2]; //?????
tmp=tmp2;//??? +1
char h[1000];
strcpy(h, res.c_str());
out << h<<endl<<strlen(h)<<endl;

res = "";
sumlen=0;
	}
while (tmp<num);
	
}

int main()
{    
	setlocale(LC_ALL, ".1251");
	ifstream is("in.txt");
	ofstream out("out.txt");
    char str1[50*20];
	is.getline(str1,70,'/0');
    alignment(str1,30,out);
	is.close();
	out.close();
	return 0;
}
