/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:19:23 by mfirdous          #+#    #+#             */
/*   Updated: 2023/07/03 23:19:23 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(const Serializer& serializer)
{
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = serializer;
}

Serializer& Serializer::operator=(const Serializer& serializer)
{
	std::cout << "Serializer copy assignment operator called" << std::endl;
	(void)serializer;
	return (*this);
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
