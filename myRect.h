#pragma once
#include <iostream>
#include <cmath>
class Rect{
	int m_left, m_right, m_top, m_bottom;
	void MakeOK();
public:
	Rect() { m_left = 0; m_right = 0; m_top = 0; m_bottom = 0; };
	Rect(int l, int r, int t, int b);
	void InflateRect(int dl, int dr, int dt, int db);
	Rect(const Rect& source);
	void InflateRect(int dh = 1, int dv = 1);
	void SetAll(int l, int r, int t, int b);
	void GetAll(int& l, int& r, int& t, int& b) const;
	void BoundingRect(const Rect& a, const Rect& b);
	friend std::ostream& operator<<(std::ostream& os, const Rect& r);
};

Rect BoundingRect(Rect a, Rect b);
Rect BoundingRect2(const Rect& a, const Rect& b);
double DistFromCent(const Rect& r);