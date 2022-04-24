#include <iostream>
using namespace std;
class Date
{
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}

	const int& getDay() const
	{
		return m_day;
	}

	const int& getMonth() const
	{
		return m_month;
	}

	const int& getYear() const
	{
		return m_year;
	}

	friend std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		os << d.m_day << '.' << d.m_month << '.' << d.m_year;

		return os;
	}
};

template <class T>
class _ptr
{
private:
	T* m_ptr;
public:
	_ptr(T* ptr = nullptr) : m_ptr(ptr) {}
	~_ptr() { delete m_ptr; }

	_ptr(_ptr& p)
	{
		m_ptr = p.m_ptr;
		p.m_ptr = nullptr;
	}

	_ptr& operator=(_ptr& p)
	{
		if (&p == this)
			return *this;

		delete m_ptr;
		m_ptr = p.m_ptr;
		p.m_ptr = nullptr;

		return *this;
	}

	T& operator*() const { return *m_ptr; }
	T* operator->() const { return m_ptr; }

	bool isNull() const { return m_ptr == nullptr; }
};

const _ptr<Date>& compares_dates(const _ptr<Date>&, const _ptr<Date>&);

void task1()
{
	_ptr<Date> today(new Date(24, 04, 2022));

	std::cout << "День: " << today->getDay() << std::endl;
	std::cout << "Меясяц: " << today->getMonth() << std::endl;
	std::cout << "Год: " << today->getYear() << std::endl;
	std::cout << "Сегодня: " << *today << std::endl;

	_ptr<Date> date;

	std::cout << "Сегодня " << (today.isNull() ? "ШОК АНО НУЛЕВОЕ\n" : "ненулевое\n");
	std::cout << "Дата " << (date.isNull() ? "ШОК АНО НУЛЕВОЕ\n" : "нотнулевое\n");

	date = today;

	std::cout << "Сегодня " << (today.isNull() ? "ДАЛАДHА АНО НУЛЕВОЕ\n" : "нЕ Нулеове\n");
	std::cout << "Дата " << (date.isNull() ? "ано нульевоье\n" : "не нулевое почeму\n");

	std::cout << "Дата: " << *date << std::endl;
}
const _ptr<Date>& compares_dates(const _ptr<Date>& a, const _ptr<Date>& b)
{
	if (a->getYear() > b->getYear())
		return a;
	else if (a->getYear() < b->getYear())
		return b;
	else
	{
		if (a->getMonth() > b->getMonth())
			return a;
		else if (a->getMonth() < b->getMonth())
			return b;
		else
		{
			if (a->getDay() > b->getDay())
				return a;
			else
				return b;
		}
	}
}

void swap_dates(_ptr<Date>& a, _ptr<Date>& b)
{
    _ptr<Date> temp;
    temp = a;
    a = b;
    b = temp;
}
void task2()
{
	_ptr<Date> date1(new Date(22, 04, 2022));
	_ptr<Date> date2(new Date(23, 04, 2022));
	_ptr<Date> date3(new Date(24, 04, 2022));

	std::cout << *compares_dates(date1, date2) << std::endl;
	swap_dates(date2, date3);
	std::cout << *compares_dates(date1, date2) << std::endl;
}

int main()
{
	task1();
    task2();
	return 0;
}
