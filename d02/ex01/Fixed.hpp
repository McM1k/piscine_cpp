/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 14:33:02 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/10 14:33:02 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed(int const intValue);
	Fixed(float const floatValue);
	~Fixed(void);
	Fixed &operator=(Fixed const &rhs); //equals

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;

private:
	int					_rawBits;
	static const int	_fractionalBits;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif