/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 14:00:18 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/17 14:00:18 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <time.h>
#include <iostream>
#include <sstream>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

void * serialize( void ){
	Data *data =  new Data;
	int i;
	std::stringstream ss;
	char c;

	i = 0;
	while (i < 8){
		c = rand() % 127;
		if (std::isalpha(c) || std::isdigit(c)){
			ss << c;
			i++;
		}
	}
	data->s1 = ss.str();

	int min = -100000;
	int max = 100000;
	data->n = min + (rand() % static_cast<int>(max - min + 1));

	std::stringstream ss2;
	i = 0;
	while (i < 8){
		c = rand() % 127;
		if (std::isalpha(c) || std::isdigit(c)){
			ss2 << c;
			i++;
		}
	}
	data->s2 = ss2.str();

	std::cout << "BEFORE CAST s1 = " << data->s1 << ", n = " << data->n << ", s2 = " << data->s2 << std::endl;
	return reinterpret_cast<void *>(data);
}

Data * deserialize( void * raw ){
	return reinterpret_cast<Data *>(raw);
}

int main(){
	srand(time(0));

	void *rawSauce;
	Data *data;

	rawSauce = serialize();
	data = deserialize(rawSauce);
	std::cout << "s1 = " << data->s1 << ", n = " << data->n << ", s2 = " << data->s2 << std::endl;
	delete data;
}