#include "Point.h"

Point::Point(int x, int y) {
	m_x = x;
	m_y = y;
}
Point& Point::operator+=(const Point& other) {
	m_x += other.m_x;
	m_y += other.m_y;
	return *this;
};
Point& Point::operator+=(int d) {
	m_x += d;
	m_y += d;
	return *this;
};
Point& operator-=(Point& f, const Point& s) {
	f.m_x -= s.m_x;
	f.m_y -= s.m_y;
	return f;
};
Point& operator-=(Point& f, int d) {
	f.m_x -= d;
	f.m_y -= d;
	return f;
};
Point::Point() {
	m_x = 0; m_y = 0;
}
Point Point::operator+(const Point& other) const {
	return Point(m_x + other.m_x, m_y + other.m_y);
}
Point Point::operator+(int d) const {
	return Point(m_x + d, m_y + d);
}
Point operator-(const Point& f, int d) {
	return Point(f.m_x - d, f.m_y - d);
}
Point operator-(const Point& f, const Point& s) {
	return Point(f.m_x - s.m_x, f.m_y - s.m_y);
}
Point operator+(int d, const Point& f) {
	return Point(d+f.m_x , d+f.m_y );
}
std::ostream& operator<<(std::ostream& os, const Point* point)
{
	std::cout << "X: " << point->m_x << "  Y: " << point->m_y << std::endl;
	return os;// TODO: insert return statement here
}
std::ostream& operator<<(std::ostream& os, const Point point)
{
	std::cout << "X: " << point.m_x << "  Y: " << point.m_y << std::endl;
	return os;// TODO: insert return statement here
}
Point Point::operator-() const {
	return Point(-m_x, -m_y);
}
const Point& Point::operator+() const {
	return *this;
}
double Point::Offset()const {
	return sqrt((m_x * m_x) + (m_y * m_y));
}
bool Point::operator<(const Point& other)const {
	return (Offset() < other.Offset());
}
bool Point::operator==(const Point& other)const {
	return ((m_x == other.m_x) && (m_y == other.m_y));
}