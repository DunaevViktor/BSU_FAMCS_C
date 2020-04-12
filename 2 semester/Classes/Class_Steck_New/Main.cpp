#include "stack.h"
#include <fstream>
#include<iostream>
#include<string>
#include<cstring>

using namespace std;
int main()
{
	ifstream in("ex1.txt");
	stack textline;
	string line;
	while(getline(in,line))
	{
		textline.push(new string(line));
	}


	stack textline2(sizeof(int)); // operator stack(const stack &r);
        for(int i=0;i<10;i++)
	{
		textline2.push(new int(i));
		//textline2.print();
	}


	string *s;
	while(!(textline.isEmpty() ))
	{
		s=(string*)textline.pop();
		cout<< *s <<endl;
		delete s;
	}

cout<<endl<<endl;

    int *s1;                  // operator stack(const stack &r);
    stack t2(textline2);
		//t2.print();

	while(!(t2.isEmpty() ))
	{
		s1=(int*)t2.pop();
		//t2.print();
		cout<< *s1 <<endl;
		delete s1;
	}
	return 0;
}