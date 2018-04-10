/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 16:10:13 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/17 16:10:13 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <time.h>

class Base {
public:
	virtual ~Base(){}
};

class A : public Base{

};

class B : public Base{

};

class C : public Base{

};

Base * generate(void){
	int rnd = (rand() % 3);

	if (rnd == 0){
		A *a = new A;
		std::cout << "it's a A" << std::endl;
		return static_cast<Base *>(a);
	}
	else if (rnd == 1) {
		B *b = new B;
		std::cout << "it's a B" << std::endl;
		return static_cast<Base *>(b);
	}
	else {
		C *c = new C;
		std::cout << "it's a C" << std::endl;
		return static_cast<Base *>(c);
	}
}

void identify_from_pointer( Base * p ){
	if (dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	else
		std::cout << "C" << std::endl;
}

void identify_from_reference( Base & p ){
	try {
		A &a = dynamic_cast<A &>(p);
		a = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e){
		try {
			B &b = dynamic_cast<B &>(p);
			b = dynamic_cast<B &>(p);
			std::cout << "B" << std::endl;
		}
		catch (std::exception &e){
			try {
				C &c = dynamic_cast<C &>(p);
				c = dynamic_cast<C &>(p);
				std::cout << "C" << std::endl;
			}
			catch (std::exception &e){
				std::cout << "unknown type" << std::endl;
			}
		}
	}

}

int main(){
	srand(time(0));
	Base *ptr = generate();
	Base &ref = *ptr;
	identify_from_pointer(ptr);
	identify_from_reference(ref);
	return 0;
}