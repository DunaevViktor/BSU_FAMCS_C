#include <iostream>
using namespace std;
int main()
{
	unsigned int x,d;
	cout <<"Input numbers"<<endl;
	cin>>x;
		if (x==1)
		{
			cout << "ne prostoe i ne sostavnoe"<<endl;
	        return 0;
		}
		if (x==2)
		{
			cout <<"prostoe"<<endl;
			return 0;
		}
		if (x%2==0)
		{
			cout<<"sostavnoe"<<endl;
			return 0;
		}
		for (d=3;d*d<=x;d+=2)
		{
			if (x%d==0)
			{
				cout <<"sostavnoe "<<d<<endl;
				return 0;
			}
		}
		cout <<"prostoe"<<endl;
		return 0;
}
