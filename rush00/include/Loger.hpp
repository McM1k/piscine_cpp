#ifndef LOGER_HPP
# define LOGER_HPP

# include <string>
# include <iostream>
# include <fstream>

class Loger
{
public:
    ~Loger();
	static std::ofstream &log();
	std::ofstream &getLog();
protected:
private:
	Loger();
	Loger(Loger const &copy);
	Loger &operator=(Loger const &rhs);
private:
	static Loger _slog;
	std::ofstream _clog;
};

#endif
