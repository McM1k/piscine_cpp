/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 21:07:59 by gboudrie          #+#    #+#             */
/*   Updated: 2018/01/17 21:07:59 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP
# include <iostream>

template<typename T>
class Array {
public:
	Array<T>(void) : _array(new T[0]), _size(0){}

	Array &operator=(Array const &rhs) {
		for (unsigned int i = 0; i < rhs._size; i++){
			this->_array[i] = rhs.getArray()[i];
		}
		this->setSize(rhs.size());
		return *this;
	} //equals

	Array(Array const &src){
		*this = src;
	}

	virtual ~Array(void){
		delete [] _array;
	}

	Array<T>(unsigned int n) : _array(new T[n]), _size(n){
		for (unsigned int i = 0; i < n; i++){
			this->_array[i] = 0;
		}
	}

	T 					*getArray() const{
		return this->_array;
	}

	unsigned int		size() const{
		return this->_size;
	}

	void				setArray(T *array){
		this->_array = array;
	}

	void				setSize(unsigned int size){
		this->_size = size;
	}

	T &operator[](unsigned int n) throw (std::exception){
		if (n >= this->size())
			throw std::exception();
		return this->getArray()[n];
	}

private:
	T				*_array;
	unsigned int	_size;
};

template<>
class Array<std::string> {
public:
	Array<std::string>(void) : _array(new std::string[0]), _size(0){}

	Array &operator=(Array const &rhs) {
		for (unsigned int i = 0; i < rhs._size; i++){
			this->_array[i] = rhs.getArray()[i];
		}
		this->setSize(rhs.size());
		return *this;
	} //equals

	Array(Array const &src){
		*this = src;
	}

	virtual ~Array(void){
		delete [] _array;
	}

	Array<std::string>(unsigned int n) : _size(n){
		this->_array = new std::string[n];
		for (unsigned int i = 0; i < n; i++){
			this->_array[i] = "";
		}
	}

	std::string				*getArray() const{
		return this->_array;
	}

	unsigned int	size() const{
		return this->_size;
	}

	void			setArray(std::string *array){
		this->_array = array;
	}

	void			setSize(unsigned int size){
		this->_size = size;
	}

	std::string &operator[](unsigned int n) throw (std::exception){
		if (n >= this->size())
			throw std::exception();
		return this->getArray()[n];
	}

private:
	std::string				*_array;
	unsigned int	_size;
};

#endif