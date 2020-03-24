#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
	struct student   // Opisanie strukturi
	{
		char name[15];
		int num;
		double grade;
	};
int cmpStudent(const void*a1, const void*b1)// 1)Sortirovka po familiyam studentov
{
	student*a = (student*)a1;
	student*b = (student*)b1;
	return strcmp(a->name, b->name);
}



int cmpStudent2(const void*a1, const void*b1)// 3)Sortirovka po grupam,a vnutri odnoi po familiyam
{
	student*a = (student*)a1;
	student*b = (student*)b1;
	if (a->num < b->num)
		return -1;
	else
	{if (a->num > b->num)
		return 1;
	else
	 return strcmp(a->name, b->name);
	}
}
void coutGroupGrades(student *MS, int n)//4)Vivesti na konsol otchet o srednem bale studentov kazdoi group
{
	double sum =0;//sum-sumirovanie,cou-col studentov,curgr-tekushaya group
	int cou = 0;
	int curgr = MS[0].num;
	for (int i = 0;i<n;i++) // prohod po vsem
	{
		if (MS[i].num == curgr)
		{
			cou++;
			sum += MS[i].grade; // esli nomer group sovpadaet s predidushei
		}
		else
		{
			sum /= (double)cou;
			cout << curgr << " Sredni ball "  << sum << endl;
			cou = 1;
			curgr = MS[i].num;
			sum = MS[i].grade;
		}
	}
	sum /= (double)cou;
	cout << curgr << " Sredni ball " << sum << endl;
}
void main()
{
	ifstream in("in.txt");
	
	student*MS;
	int n;
	cin>>n;
	MS = new student[n];
	for(int i=0;i<n;i++)
	{
	in>>MS[i].name;
	in >>MS[i].num;
    in >>MS[i].grade;
	}
	qsort(MS, n, sizeof(student), cmpStudent);
	cout<<endl;
for(int i=0;i<n;i++)
{
cout<<MS[i].name<<" "<<MS[i].num<<" "<<MS[i].grade;
cout<<endl;
}
qsort(MS, n, sizeof(student), cmpStudent2);
cout<<endl;
for(int i=0;i<n;i++)
{
cout<<MS[i].name<<" "<<MS[i].num<<" "<<MS[i].grade;
cout<<endl;
}
cout<<endl;
coutGroupGrades(MS,n);
cout<<endl;
qsort(MS, n, sizeof(student), cmpStudent);
cout<<endl;
student A;
cin.get();
	cin.getline(A.name,14);
	student*b=(student*)bsearch(&A,MS,n,sizeof(student),cmpStudent);
	if(b)
	{
		cout<<b->num<<" group,ball: "<<b->grade<<endl;
	}
	else
	{
		cout<<"ne naideno"<<endl;
	}

delete[]MS;

}