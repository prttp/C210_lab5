// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <tchar.h>
#include "Point.h"
#include "lab5/Print.h"
#include "myRect.h"


using namespace std;	
#define	  stop __asm nop


int _tmain(int argc, _TCHAR* argv[])
{
	
///////////////////////////////////////////////////////////////////
	
		//Задание 1. Итераторы

		//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
		//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
		//являются копиями элементов set, но упорядочены по убыванию
		Point p1(1, 1);
		Point p2(2, 2);
		Point p3(3, 3);
		Point p4(1, 3);
		vector<Point> vPoint{ p1, p2, p3, p4 };
		set<Point> sPoint(vPoint.begin(), vPoint.end());
		vector<Point> vPointRev(sPoint.rbegin(), sPoint.rend());
		stop
		//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
		//vector и set из предыдущего задания на экран.
		ostream_iterator<Point> it(cout, "\n");
		cout << "\n\nThe set:\n";
		copy(sPoint.begin(), sPoint.end(), it);

		cout << "\n\nThe vector:\n";
		copy(vPointRev.begin(), vPointRev.end(), it);

		//Итераторы вставки. С помощью возвращаемых функциями:
		//back_inserter()
		//front_inserter()
		//inserter()
		//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
		//какие из итераторов вставки можно использовать с каждым контейнером.
		copy(sPoint.begin(), sPoint.end(), back_inserter(vPointRev));

		cout << "\n\nThe vector:\n";
		copy(vPointRev.begin(), vPointRev.end(), it);


	
///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон
	cout << "\n\nfor_each:\n";
	for_each(vPointRev.begin(), vPointRev.end(), Output<Point>);


	stop

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката
	{
			cout << "\n\nfor_each changed:\n";
			for_each(vPointRev.begin(), vPointRev.end(), ChangeCoord<int>(5, 5));
			for_each(vPointRev.begin(), vPointRev.end(), Output<Point>);
			
	}



	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.
	{
		vector<Point> vPointRev2(sPoint.rbegin(), sPoint.rend());

		vector<Point>::iterator it = vPointRev2.begin();

		while (it != vPointRev2.end())
		{
			it = find(it, vPointRev2.end(), Point(2, 2));
			if (it == vPointRev2.end()) { break; };
			cout << *it;
			it++;
		}
	}


	
	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	{
		vector<Point> vPointRev2(sPoint.rbegin(), sPoint.rend());
		cout << "\n\nSort: \n";
		sort(vPointRev2.begin(), vPointRev2.end());
		//for_each(vPointRev2.begin(), vPointRev2.end(), Output<Point>);
		for_each(vPointRev2.begin(), vPointRev2.end(), [&vPointRev2](Point p) {std::cout << p << "\n"; });
	}



	
	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].
	{

		cout << "\n\nPointFinder: \n";
		vector<Point> vPointRev2(sPoint.rbegin(), sPoint.rend());
		vector<Point>::iterator it = vPointRev2.begin();

		while (it != vPointRev2.end())
		{
			it = find_if(it, vPointRev2.end(), PointFinder<int>(2, 2));
			if (it == vPointRev2.end()) { break; };
			cout << *it;
			it++;
		}
	}


	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	cout << "\n\nRects before sorting: \n";
	Rect aR[] = { {11, 15, 3, 25}, {14, 2,3, 17}, {2, 2, 10, 6} };
	for_each(begin(aR), end(aR), Output<Rect>);

	sort(begin(aR),end(aR),	[](Rect a, Rect b) {return DistFromCent(a) < DistFromCent(b); }	);
	cout << "\n\nRects after sorting: \n";
	for_each(begin(aR), end(aR), Output<Rect>);






	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()
		string str("TESTTEST");
		transform(str.begin(), str.end(), str.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
		cout << str<< endl;

		//Заполните list объектами string. С помощью алгоритма transform сформируте
		//значения "пустого" set, конвертируя строки в нижний регистр
		list<string> lStr;
		lStr.push_back("TEST");
		lStr.push_back("HELLO");
		lStr.push_back("WORLD");
		
		set<string>  sStr;
		insert_iterator<set<string>> it(sStr, sStr.begin());

		transform(lStr.begin(), lStr.end(), it, [](string& s) -> string {
			transform(s.begin(), s.end(), s.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
			return s;
			});


		for_each(begin(sStr), end(sStr), Output<string>);



		stop
	}
	
	{//copy_if
		//Дан вектор с элементами типа string. С помощью copy_if() требуется
		//вывести сначала строки, начинающиеся с буквы "А" или "а", затем с "Б"...
		//При этом порядок строк в исходном векторе менять не нужно!
		vector<string> vStr{ "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", "Sun" }; ///////////////////////////////////////FLAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAG
		char X = 'A';
		char x = 'a';
		do {
			copy_if(vStr.begin(), vStr.end(),
				std::ostream_iterator<string>(std::cout, " "),
				[X,x](string& s) { return ((s.front() == X) || (s.front() == x)); });
			X++;
			x++;
		} while (X != 'Z');
		stop

		//Дан multimap, содержаций пары: "месяц - количество денй в месяце"
		//pair<string, int>. С помощью copy_if сформируйте ДВА map-а: первый -
		//с парами, содержащими четное количество дней, 2-ой - нечетное.
		multimap<string, int> month {
			{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};
		map<string, int> monthOdd;
		map<string, int> monthEven;
		insert_iterator<map<string, int>> itO(monthOdd, monthOdd.begin());
		copy_if(month.begin(), month.end(),
			itO,
			[](const pair<string, int>& p) { return (p.second % 2 != 0); });
		
		stop
		insert_iterator<map<string, int>> itE(monthEven, monthEven.begin());
		copy_if(month.begin(), month.end(),
				itE,
				[](pair<string, int> p) { return (p.second % 2 == 0); });
		//Распечатайте multimap и map-ы, используя написанный вами ранее шаблон
		//функции, выводящей элементы ЛЮБОГО контейнера на печать.
		//Что нужно сделать дополнительно для вывода пары?
		PrintLeg(month);
		PrintLeg(monthOdd);
		PrintLeg(monthEven);
	
		stop
	}

	return 0;
}

