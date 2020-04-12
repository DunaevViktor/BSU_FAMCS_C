#include<iostream>
#include<ctime>
using namespace std;

////////////////////Шаблон для статического массива///////////////////////////
//
//template <class type, int size>
//class array
//{
//	type array[size];
//public:
//	class out_of_bounds{};
//	type& operator[](int index);
//};
//template <class type, int size>
//inline type& array <type, size>::operator[](int index)
//{
//	if (0 <= index && index < size)
//		return array[index];
//	throw out_of_bounds;
//}
//
//int main()
//{
//	try
//	{
//		array <int, 10> arr;
//		arr[0] = arr[2];
//		arr[1] = 2;
//		arr[20] = 5;
//	}
//	catch (array<int, 10>::out_of_bounds())
//	{
//		cout << "Выход за пределы массива";
//	}
//	return 0;
//}

/////////////////////Шаблон для динамического массива////////////////////////
struct out_of_bounds {

	int ind;

	out_of_bounds(int ind1)
	{		ind = ind1;
}

};
template <class type>
class array
{
	type* arr;
	int size;
public:
	virtual ~array(void);
	array(int size = 128);

	type& operator[](int index);
};

template <class type>
inline type& array<type>::operator[](int index)
{
	if (0 <= index && index < size)
		return arr[index];
	throw out_of_bounds(index);
}

template <class type>
array<type>::~array(void)
{
	delete[]arr;
}

template <class type>
array<type>::array(int sz = 128) : size(sz), arr(new type[sz])
{
}

template<class type, int size1>
class sized_array :public array<type>
{
public:
	sized_array() :array(size1)
	{
	}
};

int main()
{
	setlocale(LC_ALL, ".1251");
	srand(time(NULL));
	try
	{
		cout << "Содздание массива из 5 элементов: " << endl;
		array<int>a1;
		sized_array<int, 5>b1;
		for (int i = 0; i < 5; i++)
		{
			b1[i] = rand() % 50;
			cout << b1[i] << " ";
		}
		cout <<endl<<endl;


		cout << "Создаем массив 5 на 7: " << endl;
		//Задаем то,что хотим массив 5 на 7
		sized_array<sized_array<int, 7>, 5> b2;
		for (int i = 0; i < 5; i++)
		for (int j = 0; j < 7; j++)
		{
			b2[i][j] = rand() % 100 + (rand() % 10)*0.1;
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << b2[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;


		cout << "Пытаемся создать массив 8 на 10: " << endl;
		cout << b2[4][10] << endl;
		cout << endl;
	}

	//Исключения
	catch (out_of_bounds& bb)
	{
		cout << "Error " << bb.ind<< endl;
	}
	return 0;
}