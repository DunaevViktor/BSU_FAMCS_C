//Из файла читается англо-французский переводчик
//go to v aller
//go at v partir
//go out v sortir
//run v courir
//melon s melon
//apple s pomme
//При выводе дописываем артикли и разделяем столбцы табуляцией
//К глаголам англ ---- to , к существительным ---- a,an
//К французским существительным ---- une,un
#include<iostream>
#include<fstream>
using namespace std;

struct Voc
{
	 char Eng1[30];
	 char Eng2[5];
     char Type[2];
	 char Fr[30];
	 // constructors and destrictors
     friend istream &operator >>(istream &in,Voc &V);
	 friend ostream &operator <<(ostream &out,Voc &V);
};
istream &operator >>(istream &in,Voc &V)
{
	char InStr[200];
	in.getline(InStr,199,'\n');//читаем строку
	char* FW = strtok(InStr,"\n ");//делим на слова
	strcpy(V.Eng1,FW);//копируем первое слово
	char* SW = strtok(0,"\n ");
    char* TW = strtok(0,"\n ");
	char* FoW = strtok(0,"\n ");
    if(FoW !=0)
	{
		strcpy(V.Eng2,SW);
		strcpy(V.Type,TW);
		strcpy(V.Fr,FoW);
	}
	else
	{
		strcpy(V.Eng2,"    ");
        strcpy(V.Type,SW);
		strcpy(V.Fr,TW);
	}
	return in;
}
ostream &operator <<(ostream &out,Voc &V)
{
if(strcmp(V.Type,"v")==0)
  {
	out<<"to  "<<V.Eng1;
  }
else
 {
	if(strchr("aeiyuo",V.Eng1[0])!=0)
	{
		out<<"an "<<V.Eng1;
	}
	else 
	{
		out<<"a "<<V.Eng1;
	}

	//out<<"\t"<<V.Eng2<<"\t"<<V.Type<<"\t";
	out << V.Eng2 << V.Type ;
    if(V.Fr[strlen(V.Fr)-1]=='e')
	{
		out<<"une "<<V.Fr<<endl;
	}
	else
	{
		out<<"un "<<V.Fr<<endl;
	}
 }
return out;
}

int main()
{
	Voc line;
	ifstream IN("A.txt");
	ofstream OUT("Z.txt");
	while(!IN.eof())
	{
		IN>>line;
		if(IN.bad())
			break;
		OUT<<line;
	}
	return 0;
}
