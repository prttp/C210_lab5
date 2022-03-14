// Iter_Alg.cpp : Defines the entry point for the console application.
//
//���������. ����������� ���������. ���������.

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
	
		//������� 1. ���������

		//����������� ���������. ����������� set<Point>. ���������, ���
		//����� ����������� � ������ Point. �������� ������, �������� �������� 
		//�������� ������� ��������� set, �� ����������� �� ��������
		Point p1(1, 1);
		Point p2(2, 2);
		Point p3(3, 3);
		Point p4(1, 3);
		vector<Point> vPoint{ p1, p2, p3, p4 };
		set<Point> sPoint(vPoint.begin(), vPoint.end());
		vector<Point> vPointRev(sPoint.rbegin(), sPoint.rend());
		stop
		//��������� ���������. � ������� ostream_iterator �������� ����������
		//vector � set �� ����������� ������� �� �����.
		ostream_iterator<Point> it(cout, "\n");
		cout << "\n\nThe set:\n";
		copy(sPoint.begin(), sPoint.end(), it);

		cout << "\n\nThe vector:\n";
		copy(vPointRev.begin(), vPointRev.end(), it);

		//��������� �������. � ������� ������������ ���������:
		//back_inserter()
		//front_inserter()
		//inserter()
		//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
		//����� �� ���������� ������� ����� ������������ � ������ �����������.
		copy(sPoint.begin(), sPoint.end(), back_inserter(vPointRev));

		cout << "\n\nThe vector:\n";
		copy(vPointRev.begin(), vPointRev.end(), it);


	
///////////////////////////////////////////////////////////////////

	//������� 2. ���������� ��������� (������������ ���� <algorithm>). ���������.

	// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
	//(������, vector, list...)
	//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
	//������������ �������� ���������
	//��������� : ������� ���������� ������� ���������� ��� ������
	cout << "\n\nfor_each:\n";
	for_each(vPointRev.begin(), vPointRev.end(), Output<Point>);


	stop

	//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
	//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
	//��� ������) � �������� ��������� � ������� ����������� ���������
	{
			cout << "\n\nfor_each changed:\n";
			for_each(vPointRev.begin(), vPointRev.end(), ChangeCoord<int>(5, 5));
			for_each(vPointRev.begin(), vPointRev.end(), Output<Point>);
			
	}



	//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
	//��� ��������� �� ������� Point � ��������� ���������.
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


	
	
	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
	////�� ��������� �������� ��������� ������������������ �� �����������.
	//��� ������ ���� ���������� � ������ Point?
	// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
	//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!
	{
		vector<Point> vPointRev2(sPoint.rbegin(), sPoint.rend());
		cout << "\n\nSort: \n";
		sort(vPointRev2.begin(), vPointRev2.end());
		//for_each(vPointRev2.begin(), vPointRev2.end(), Output<Point>);
		for_each(vPointRev2.begin(), vPointRev2.end(), [&vPointRev2](Point p) {std::cout << p << "\n"; });
	}



	
	//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
	//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
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


	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
	//���������� �������������� �� �������� ������ �� ������ ���������.
	cout << "\n\nRects before sorting: \n";
	Rect aR[] = { {11, 15, 3, 25}, {14, 2,3, 17}, {2, 2, 10, 6} };
	for_each(begin(aR), end(aR), Output<Rect>);

	sort(begin(aR),end(aR),	[](Rect a, Rect b) {return DistFromCent(a) < DistFromCent(b); }	);
	cout << "\n\nRects after sorting: \n";
	for_each(begin(aR), end(aR), Output<Rect>);






	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()
		string str("TESTTEST");
		transform(str.begin(), str.end(), str.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); });
		cout << str<< endl;

		//��������� list ��������� string. � ������� ��������� transform ����������
		//�������� "�������" set, ����������� ������ � ������ �������
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
		//��� ������ � ���������� ���� string. � ������� copy_if() ���������
		//������� ������� ������, ������������ � ����� "�" ��� "�", ����� � "�"...
		//��� ���� ������� ����� � �������� ������� ������ �� �����!
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

		//��� multimap, ���������� ����: "����� - ���������� ���� � ������"
		//pair<string, int>. � ������� copy_if ����������� ��� map-�: ������ -
		//� ������, ����������� ������ ���������� ����, 2-�� - ��������.
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
		//������������ multimap � map-�, ��������� ���������� ���� ����� ������
		//�������, ��������� �������� ������ ���������� �� ������.
		//��� ����� ������� ������������� ��� ������ ����?
		PrintLeg(month);
		PrintLeg(monthOdd);
		PrintLeg(monthEven);
	
		stop
	}

	return 0;
}

