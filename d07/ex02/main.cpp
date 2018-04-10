/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:00:17 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/17 21:00:17 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Array.tpp"

int main() {
	Array<int> *arInt = new Array<int>(4);
	(*arInt)[0] = 10;
	(*arInt)[1] = 2;
	unsigned int i;
	for(i = 0; i < arInt->size(); i++)
		std::cout << (*arInt)[i] << std::endl;
	delete arInt;

	Array<std::string> arStr(3);
	arStr[0] = "poulet";
	arStr[1] = "braisay";
	arStr[2] = "avec sa soos";
	for(i = 0; i < arStr.size(); i++)
		std::cout << arStr[i] << std::endl;
}