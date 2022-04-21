#include <iostream>
#include <cstdint>
#include <string>
using namespace std;

//task 1
class shape {
	virtual ~shape() {}
	virtual double area() const = 0;
};
class circle : public shape {
public:
	circle(size_t r) : m_r(r){ }
	doutble area() const {
		return M_PI * m_r * m_r;
	}

private:
	size_t m_r;
};
class rectangle : public shape {
public:
	rectangle(size_t w,size_t h) : m_w(w),m_h(h){ }
	double area() const {
		return m_w * m_h;
	}

private:
	size_t m_w;
	size_t m_h;
};

int main()
{
	shape();
	area();
	circle();
	area();
	rectangle();
	area();
}