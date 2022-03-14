#include "myRect.h"
Rect::Rect( int l, int r, int t, int b) {
	m_left = l; m_right = r; m_top = t; m_bottom = b; MakeOK();
};


void Rect::MakeOK() {
	int buff = 0;
	if (m_left > m_right) { buff = m_left; m_left = m_right; m_right = buff; };
	if (m_bottom > m_top) { buff = m_bottom; m_bottom = m_top; m_top = buff; };
};

void Rect::InflateRect(int dl, int dr, int dt,  int db)
{
	m_left -= dl;
	m_right += dr;
	m_bottom -= db;
	m_top += dt;
	MakeOK();
};
Rect::Rect(const Rect& source) {
	m_left = source.m_left;
	m_right = source.m_right;
	m_bottom = source.m_bottom;
	m_top = source.m_top;
};
void Rect::InflateRect(int dh, int dv) {
	m_right += dh;
	m_top += dv;
	MakeOK();
};
void Rect::SetAll(int l, int r, int t, int b) {
	m_left = l;
	m_right = r;
	m_bottom = b;
	m_top = t;
	MakeOK();
};
void Rect::GetAll(int& l, int& r, int& t, int& b) const {
	l = m_left;
	r = m_right;
	b = m_bottom;
	t = m_top;
};
std::ostream& operator<<(std::ostream& os, const Rect& r)
{
	int al, ar, at, ab;
	r.GetAll(al, ar, at, ab);
	os << "Top left coord: (" << al << ", " << at << ")  Bottom right coord: (" << ar << ", " << ab << ")\n";
	return os;// TODO: insert return statement here
}
Rect BoundingRect(Rect a, Rect b) {
	int al, ar, at, ab, bl, br, bt, bb, rl, rr, rt, rb;
	a.GetAll(al, ar, at, ab);
	b.GetAll(bl, br, bt, bb);
	(al < bl) ? rl = al : rl = bl;
	(ar > br) ? rr = ar : rr = br;
	(at > bt) ? rt = at : rt = bt;
	(ab < bb) ? rb = ab : rb = bb;
	Rect res(rl, rr, rt, rb);
	return res;
}
Rect BoundingRect2(const Rect& a, const Rect& b) {
	int al, ar, at, ab, bl, br, bt, bb, rl, rr, rt, rb;
	a.GetAll(al, ar, at, ab);
	b.GetAll(bl, br, bt, bb);
	(al < bl) ? rl = al : rl = bl;
	(ar > br) ? rr = ar : rr = br;
	(at > bt) ? rt = at : rt = bt;
	(ab < bb) ? rb = ab : rb = bb;
	Rect res(rl, rr, rt, rb);
	return res;
}
void Rect::BoundingRect(const Rect& a, const Rect& b) {
	(a.m_left < b.m_left) ? m_left = a.m_left : m_left = b.m_left;
	(a.m_right > b.m_right) ? m_right = a.m_right : m_right = b.m_right;
	(a.m_top > b.m_top) ? m_top = a.m_top : m_top = b.m_top;
	(a.m_bottom < b.m_bottom) ? m_bottom = a.m_bottom : m_bottom = b.m_bottom;
	}
double DistFromCent(const Rect& r)
{
	int al, ar, at, ab;
	r.GetAll(al, ar, at, ab);

	return sqrt(pow((ar-al)/2, 2) + pow((at-ab)/2, 2));
}
