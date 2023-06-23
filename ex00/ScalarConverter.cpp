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

bool isFloat(std::string str)
{
	size_t	point_index;

	point_index = str.find('.');
	if (point_index == std::string::npos || point_index >= str.length() - 2)
		return false;
	if (str[str.length() - 1] != 'f')
		return false;
	return true;
}

int getType(std::string literal)
{
	// char *end;

	// strtol(literal.c_str(), &end, 0);
	// if (!*end)
	// 	return INT;
	// strtod(literal.c_str(), &end);
	// if (!*end)
	// 	return DOUBLE;
	// strtof(literal.c_str(), &end);
	// if (!*end)
		// return FLOAT;
	// if (literal[0] > 31 && literal[0] < 127)
	// return CHAR;

	int		i;
	float	f;
	double	d;
	char	c;
	std::istringstream ss(literal);

	if (ss.str().find('.') != std::string::npos && ss >> f && ss.peek() == 'f')
	{
		std::cout << "Float: " << f << std::endl;
		return FLOAT;
	}
	
	std::cout << "next char = " << ss.peek() << std::endl;
	ss.clear();
	ss.seekg(0);
	if (ss.str().find('.') != std::string::npos && ss >> d)
	{
		std::cout << "Double: " << d << std::endl;
		return DOUBLE;
	}
	ss.clear();
	ss.seekg(0);
	if (ss >> i)
	{
		std::cout << "Int: " << i << std::endl;
		return INT;
	}
	ss.clear();
	ss.seekg(0);
	if (ss >> c)
	{
		std::cout << "Char: " << c << std::endl;
		return CHAR;
	}
	return (CHAR);
}

void ScalarConverter::convert(std::string literal)
{
	getType(literal);
}