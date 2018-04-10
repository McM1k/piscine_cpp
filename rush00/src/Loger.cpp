#include <iostream>
#include "Loger.hpp"

Loger Loger::_slog;

Loger::Loger()
{
//	_clog.open("/dev/ttys000", std::ios::out);
	 _clog.open("log.log", std::ios::out | std::ios::trunc);
}

Loger::~Loger()
{
	_clog.close();
}

Loger::Loger(Loger const &copy)
{
	*this = copy;
}

Loger &Loger::operator=(Loger const &rhs)
{
	(void)rhs;
	return (*this);
}
std::ofstream &Loger::log()
{
	return (_slog.getLog());
}
std::ofstream &Loger::getLog()
{
	return (this->_clog);
}
