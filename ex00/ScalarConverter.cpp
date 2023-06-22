/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:17:49 by mfirdous          #+#    #+#             */
/*   Updated: 2023/06/22 16:53:16 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

//			0		1		2	  3		4
enum type {CHAR, NON_CHAR, INT, FLOAT, DOUBLE};

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& converter)
{
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = converter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& converter)
{
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	(void)converter;
	return (*this);
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

int getType(std::string literal)
{
	char *end;

	// strtol(literal.c_str(), &end, 0);
	// if (!*end)
	// 	return INT;
	// strtod(literal.c_str(), &end);
	// if (!*end)
	// 	return DOUBLE;
	strtof(literal.c_str(), &end);
	if (!*end)
		return FLOAT;
	// if (literal[0] > 31 && literal[0] < 127)
	return CHAR;
}

void ScalarConverter::convert(std::string literal)
{
	std::cout << "type is " << type(getType(literal)) << std::endl;
}