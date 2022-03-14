#pragma once
template <typename T>
void Output(const T& s)
{
	std::cout << s << "\n";
}
template <typename T>
class ChangeCoord
{
	T m_cX;
	T m_cY;
public:
	ChangeCoord(T x = T(), T y = T()) : m_cX(x), m_cY(y) {};
	void operator() (Point& p) { p.SetX(m_cX); p.SetY(m_cY); };
};
template <typename T>
class PointFinder
{
	T m_X;
	T m_Y;
public:
	PointFinder(T x = T(), T y = T()) : m_X(x), m_Y(y) {}
	bool operator() (Point& p) { return (p.GetX() >= -m_X) ? ((p.GetX() <= m_Y) ? ((p.GetY() >= -m_X) ? ((p.GetY() <= m_Y) ? 1 : 0) : 0) : 0) : 0; }
};
template<typename C>
void PrintLeg(const C& cont) {
	std::cout << typeid(cont).name() << std::endl << "Size: " << cont.size() << "   Maximal size: " << cont.max_size() << std::endl;
	auto itBeg = cont.begin();
	int size = cont.size();
	for (int i = 0; i < size; i++) {
		std::cout << *itBeg << std::endl;
		++itBeg;
	}
}
template<typename T1, typename  T2 >
std::ostream& operator<<(std::ostream& os, const std::pair<T1, T2>& s) {
	return os << s.first << "  " << s.second;
}
