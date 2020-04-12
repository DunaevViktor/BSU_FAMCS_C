/*Разработать программу форматирования текста, который находится в текстовом файле.
Программа должна ввести с консоли имя файла, в котором находится текст, 
а затем запросить у пользователя ширину строки.
Текст должен быть отформатирован следующим образом:
	- ширина строк должна совпадать с заданной шириной строки;
	- перенос слов не допускается;
	- для выравнивания строк, между словами вставляются дополнительные пробелы;
    - последняя строка обзаца прижата к левому краю;
	- будем считать, что разделителем между словами является " ";
	- знак табуляции обозначает новый абзац. */
#include<iostream>
#include<fstream>
using namespace std;
//Функция,которая разбивает строку на массив слов
int tokens(char* str,char** mas)
{
	char raz[]=" \n";//Разделители
    mas[0]=strtok(str,raz);
	int index=1;
	while(!(mas[index]= strtok(0,raz))==0)
	{
		index++;
	}
  return index;
}
//Функция,которая берет обзац,форматирует его и выводит на экран(в файл)
//Строка-обзац,количество символов,поток вывода
void alignment(char* str,int len,ostream &out)
{
	int ob=0;//kol uze napisanih slov
	int sumlen=0;//Общая длинна слов в строке(без пробелов)
	int num;//Общее количество всех слов в обзаце
    int countw;//Счетчик для слов
	int counts;//Счетчик для пробелов
	int ost;//Лишние пробелы,которые нарушают неравномерность
	char** words=new char*[50*20];//Массив слов обзаца(без интервалов),не более 50 слов в строке, и 20 строк в обзаце
	string spaces("                    ");//Массив пробелов(20 штук)
    string res;//Результирующая строка 

	num=tokens(str,words);
	int tmp=0;//номер слова в начале следующей строки

do
	{
	//Номер текущего слова 
int	countw2=0;//кол слов в текущей строке
	while((countw2+tmp<num )&&((sumlen+countw2+tmp-1+strlen(words[countw2+tmp]))<len)) //Пока длинна строки меньше заданной
	{
		sumlen+=strlen(words[countw2+tmp]);//Добавляем слова temp+countw
		if (tmp+countw2<num)
			countw2++;//подсчитываем слова , которые не должны выходить за предел
		else 
			break;
	}
	if (countw2 == 0)
	{
		break;
	}
	
	//коунтв кол слов которые нужно вписать , коунтв -1 пробелы 
	int ost=len-sumlen-(countw2-1); //temp+countw //strlen(words[countw])-
//отнимем длинна всех слов и общее количество пробелов , получили остаток
//c-длинна обязательной прибавки
//o-количесвто интервалов в которые дополнительно по одному пробелу
	int c,o;
	if (countw2 > 1)
	{
		c = ost / (countw2 - 1);
		o = ost % (countw2- 1);
	}
	else
	{
		c = ost;//один пробел
		o = 0;//ничего не добавлять
	}
int tmp2=0;//?
tmp2=tmp;
string s1(spaces.substr(0,1+c));
for(int i=0;i<countw2-1;i++) //i количество добавленных слов //-1
{
	res+=(words[tmp2++]);
	res+=s1;//пробелы
	if(i<o)
		res+=" ";//доп пробелы
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
