#pragma once
#include <iostream>
class Point
{
	int m_x, m_y;
public:
	explicit Point(int x, int y);
	Point();
	Point& operator+=(const Point& other);
	Point& operator+=(int d);
	friend Point& operator-=(Point& f, const Point& s);
	friend Point& operator-=(Point& f, int d);
	Point operator+(const Point& other) const;
	Point operator+(int d) const;
	friend Point operator-(const Point& f, int d);
	friend Point operator-(const Point& f, const Point& s);
	friend Point operator+(int d, const Point& f);
	friend std::ostream& operator<<(std::ostream& os, const Point* point);
	friend std::ostream& operator<<(std::ostream& os, const Point point);
	Point operator-() const;
	const Point& operator+() const;
	bool operator< (const Point&)const;
	bool operator==(const Point&)const;
	double Offset()const;
	int GetX() { return m_x; };
	int GetY() { return m_y; };
	void SetX(int x) { m_x = x; };
	void SetY(int y) { m_y = y; };
};
Point& operator-=(Point& f, const Point& s);
Point& operator-=(Point& f, int d);
Point operator-(const Point& f, int d);
Point operator-(const Point& f, const Point& s);
Point operator+(int d, const Point& f);