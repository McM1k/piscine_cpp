/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:06:56 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/16 20:06:56 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include <iostream>
#include <cstdlib>
#include <iomanip>

int main(int ac, char **av){
	if (ac != 2)
		return 1;
	double valued = std::strtod(av[1], nullptr);
	float valuef = static_cast<float>(valued);
	int valuei = static_cast<int>(valued);
	char valuec = static_cast<char>(valued);

	if (!(valued <= DBL_MAX && valued >= -DBL_MAX))
		std::cout << "char: Impossible." << std::endl << "Int: Impossible." <<std::endl;

	else {
		if (valued < 0 || valued > 127 || valued - valuec != 0)
			std::cout << "char: Impossible." << std::endl;
		else if (!(valued >= 32 && valued < 127))
			std::cout << "char: Non displayable." << std::endl;
		else
			std::cout << "char: '" << valuec << "'" << std::endl;

		if (valued > 2147483647 || valued < -2147483648)
			std::cout << "Int: Impossible." << std::endl;
		else
			std::cout << "int: " << valuei << std::endl;
	}

		std::cout << "float: " << std::fixed;
		std::cout << std::setprecision(1) << valuef << "f" << std::endl;

		std::cout << "double: " << std::fixed;
		std::cout << std::setprecision(1) << valued << std::endl;


	return 0;
}