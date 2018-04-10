/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 20:24:07 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/17 20:24:07 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

template <typename T>
void		iter(T addr, int length, void (*fct)(T)) {
	int	i = 0;
	while (i < length) {
		fct(addr);
		addr++;
		i++;
	}
};

template <typename U>
void f(U i){
	*i *= 3;
}

int main(){
	int tab[10] = {1,2,4,6,20,20,8,5,7,9};
	iter(tab, 10, &(f<int *>));
	for (int i = 0; i < 10; i++) {
		std::cout << tab[i] << std::endl;
	}

	char tab1[3] = {'*','*','*'};
	iter(tab1, 3, &(f<char *>));
	for (int i = 0; i < 3; i++) {
		std::cout << tab1[i] << std::endl;
	}
}