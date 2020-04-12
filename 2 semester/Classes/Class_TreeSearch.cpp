#include<iostream>
#include<ctime>
using namespace std;
struct node
{
	int key;
	node *left; //левый поворот
	node *right; //правый поворот

};
class TreeSearch
{
	
public:
	node *root;
	TreeSearch():root(NULL)
	{
	}
//функция поиска элемента в дереве , возвращает 
// "true" если элемент найден
	bool Find(int key1,node *r)
	{
		if(r==NULL)
		return 0;
		if(r->key==key1)
			return true;
		if(key1<r->key)
		{
			if(r->left)
				return Find(key1,r->left);
			else 
				return false;
		}
		else
		{
			if(r->right)
				return Find(key1,r->right);
			else 
				return false;
		}
	}
//функция добавления элемента в дерево
void Add(int key1)
{
	node *N=new node();
	N->key=key1;
	N->left=NULL;
	N->right=NULL;
	node *t=root;
	if(root==NULL)
	{
		root=N;
		return;
	}
	do
	{
		if(key1<=t->key)
			if(t->left==NULL)
			{
				t->left=N;
				break;
			}
			else
			{
				t=t->left;
				continue;
			}
		else
			if(t->right==NULL)
			{
				t->right=N;
				break;
			}
			else
			{
				t=t->right;
			}
	}
while(true);
}
void print(node *t)//print
{
	if(t==0)
		return;
	else
		print(t->left);
	cout<<t->key<<" ";
	    print(t->right);
}
};
int main()
{
	srand(time(NULL));
	TreeSearch A;
	int *mas;
	int n=10;
	mas=new int[n];
	for(int i=0;i<n;i++)
	{
		mas[i]=rand()%100+1;
	}
	cout<<"Massiv: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<mas[i]<<" ";
	}
	cout<<endl;
    for(int i=0;i<n;i++)
	{
		A.Add(mas[i]);
	}
	cout<<"Our Tree: "<<endl;
    A.print(A.root);
	cout<<endl;
	
	int l;
	cout<<"Element dlya dobavleniya?"<<endl;
	cin>>l;
	A.Add(l);
	cout<<"New Massiv: "<<endl;
	A.print(A.root);
	cout<<endl;

	int h;
	cout<<"Element dlya poiska one?"<<endl;
	cin>>h;
	bool d = A.Find(h,A.root);
	if(d==1)
	{
		cout<<"Operation good"<<endl;
	}
	if(d==0)
	{
		cout<<"Sorry,not found"<<endl;
	}


	
	int h1;
	cout<<"Element dlya poiska two?"<<endl;
	cin>>h1;
	bool d1 = A.Find(h1,A.root);
	if(d1==1)
	{
		cout<<"Operation good"<<endl;
	}
	if(d1==0)
	{
		cout<<"Sorry,not found"<<endl;
	}

	return 0;
}
