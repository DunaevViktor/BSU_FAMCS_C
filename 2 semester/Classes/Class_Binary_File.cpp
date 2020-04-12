#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Dword
{
	char first[30]; //dlya perevoda
	char second[30];//slovo bez articlya,perevod
	Dword()
	{
		strcpy(first, " ");
		strcpy(second, " ");
	}
	Dword(char *F1, char *S1)
	{
		strcpy(first, F1);
		strcpy(second, S1);
	}
};
int FirstCmp(const void*a1, const void*b1)
{
	Dword *a=(Dword*)a1;
	Dword *b=(Dword*)b1;
	return strcmp(a->first,b->first);
}
class Voc
{
	Dword *mas;
	int n;
public:
	Voc()
	{
		mas = new Dword[10000];
	}
	Voc(Dword *f)
	{
		mas=f;
		
	}
	bool Read(char*name)
	{
		ifstream in(name);
		if (!in.good())
		{
			return false;
		}
		int i = 0;
		while (!in.eof())
		{
			char line[70];
			in.getline(line, 69, '\n');
			if (in.bad())
				break;
			strcpy(mas[i].first, strtok(line, " -"));
			strcpy(mas[i].second, strtok(0, " -"));
			i++;
		}
		n = i;
		in.close();
		return true;
	}
	void SortFirst()
	{
		qsort(mas, n, sizeof(Dword), FirstCmp);
	}
	bool Write(char*name)
	{
		ofstream out;
		out.open(name, ios::binary);
		for (int k = 0; k < n; k++)
		{
			out.write((char*)&mas[k], sizeof(Dword));
		}
		out.close();
		return true;
	}
void Writec()
{
	for(int i=0;i<n;i++)
	{
		cout<<mas[i].first<<" - "<<mas[i].second<<endl;
	}
}
	~Voc()
	{
		delete[]mas;
	}

};
class binwork
{
	Dword d;//структура 
	fstream f;
public:
//параметры конструктора -- строка и параметр для открытия 
	binwork()
	{}
string Search(string key)
{
	f.open("out.bin",ios::in|ios::binary);//проверка на открытие
int l;//левая
int r;//правая
int c;//средняя
//Заводим эту переменную,чтобы узнать центр дробное ли число?
//Если дробное то по умолчанию округление в меньшую сторону, 
//А нам нужно в большую.

//double dc;
l=0;
f.seekg(0,ios::end);
r=f.tellg()/sizeof(Dword);
c=(r+l)/2;
while(r>=l)
   {
c=(r+l)/2;
//dc = (r + l)*0.5;
//if (dc - c > 0 && abs(r - l) != 1)
//c++;
f.seekg(c*sizeof(Dword),ios::beg);
f.read((char*)&d,sizeof(Dword));
int k = (strcmp(key.c_str(), d.first) /*== 0*/);
/*cout << "left " << l << endl;
cout << "right " << r << endl;
cout << "centr " << c << endl;
cout << "dcentr " << dc << endl;
cout << "k " << k << endl;*/
if(k==0)
   {
//кей совпало с чем-то из структуры
string res(d.second);
return res;
   }

if(r==l) //Почему то портится правый флаг????
      {
string res2(d.second);
return res2;
      }

if (r == c || l == c)
{
	string res1("Error -_-");
	return res1;
}

if(k<0)
  {
    r=c;
	continue;
  }
else
  {
	l = c;
	continue;
  }

 }//while
}
~binwork()
{
}
};

int main()
{
	setlocale(LC_ALL, ".1251");
	Voc D;
	binwork os;
	char name[100],key[30];

	bool twot = D.Read("in1.txt");
	D.SortFirst();
	bool twor = D.Write("out.bin");
	D.Writec();

	cout <<endl<<endl<< "Что хотите перевести?" << endl;
	cin.getline(key, 29, '\n');
	string answer = os.Search(key);
	cout << answer << endl;
	return 0;
}
