/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:10:27 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/09 10:10:27 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#import "Pony.hpp"

void	ponyOnTheHeap(){
	Pony *ponyOnTheHeap = new Pony("OnTheHeap");
	ponyOnTheHeap->doSomeStuff();
	delete ponyOnTheHeap;
}

void	ponyOnTheStack(){
	Pony ponyOnTheStack("OnTheStack");
	ponyOnTheStack.doSomeStuff();
}

int main() {
	std::cout << std::endl;
	ponyOnTheHeap();
	std::cout << std::endl;
	ponyOnTheStack();
	std::cout << std::endl;
	return 0;
}