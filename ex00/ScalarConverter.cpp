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

	if (str[str.length() - 1] != 'f')
		return false;
	point_index = str.find('.');
	if (point_index == std::string::npos || point_index >= str.length() - 2) // point was not found OR the num is of the form xxxx.f and not xxxx.xf
		return false;
	return true;
}

bool	convertFloat(std::string literal)
{
	std::string str = literal;
	char *end;
	float f;
	const float max_safe = 2147483647.f; // 2^31 - 128 
    const float low_safe = -2147483648.f; // -2^31 

	if (!isFloat(literal))
		return (false);
	str.erase(str.length() - 1, 1);
	f = strtof(str.c_str(), &end);
	if (*end)
		return false;

	std::cout << "char: ";
	if (f > 31 && f < 127)
		std::cout << static_cast<char>(f) << std::endl;
	else if (f > 255)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "non displayable" << std::endl;
	
	std::cout << "int: ";
	if (f > max_safe || f < low_safe)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(f) << std::endl;
	
	std::cout << "float: ";
	if (fmod(f, 1) == 0)
		std::cout << f << ".0f" << std::endl;
	else
		std::cout << f << "f" << std::endl;
	
	std::cout << "double: " << static_cast<double>(f) << std::endl;
	return true;
}

bool convertDouble(std::string literal)
{
	char *end;
	float f;
	const float max_safe = 2147483647.f; // 2^31 - 128 
    const float low_safe = -2147483648.f; // -2^31 

	
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
	double	d;
	char	c;
	std::istringstream ss(literal);
	
	if (convertFloat(literal))
		return FLOAT;
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