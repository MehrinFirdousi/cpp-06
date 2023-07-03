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

//			0		1		2	3		4
enum type {FLOAT, DOUBLE, INT, CHAR, INVALID};
# define SCI_LIMIT 999999

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

void	printFloat(float f)
{
	std::cout << "float: " << f;
	if (fmod(f, 1) == 0 && (f <= SCI_LIMIT && f >= -SCI_LIMIT)) // if the float doesn't have a decimal portion and it wont become scientific notation
		std::cout << ".0f" << std::endl;
	else
		std::cout << "f" << std::endl;
}

void	printDouble(double d)
{
	std::cout << "double: " << d;
	if (fmod(d, 1) == 0 && (d <= SCI_LIMIT && d >= -SCI_LIMIT))
		std::cout << ".0";
	std::cout << std::endl;
}

void	printInt(double num)
{
	const float max_safe = 2147483520.f; // 2^31 - 128 - this is the last safe value where float can be cast to int without overflow
    const float min_safe = -2147483648.f; // -2^31 

	std::cout << "int: ";
	if (num > max_safe || num < min_safe)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
}

void	printChar(double c)
{
	std::cout << "char: ";
	if (c > 31 && c < 127)
		std::cout << static_cast<char>(c) << std::endl;
	else if (c > 255 || c < 0)
		std::cout << "impossible" << std::endl;
	else
		std::cout << "non displayable" << std::endl;
}

bool isPseudoLiteral(std::string literal)
{
	if (literal.compare("-inf") == 0 || literal.compare("+inf") == 0 || literal.compare("nan") == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << "f" << std::endl;
		std::cout << "double: " << literal << std::endl;
		return true;
	}
	else if (literal.compare("-inff") == 0 || literal.compare("+inff") == 0 || literal.compare("nanf") == 0)
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << literal << std::endl;
		std::cout << "double: " << literal.substr(0, literal.length() - 1) << std::endl;
		return true;
	}
	return false;
}

bool	convertFromFloat(std::string literal)
{
	std::string str = literal;
	char *end;
	float f;
	
	if (isPseudoLiteral(literal))
		return true;
	if (!isFloat(str))
		return false;
	str.erase(str.length() - 1, 1);
	f = strtof(str.c_str(), &end);
	if (*end)
		return false;
	printChar(f);
	printInt(f);
	printFloat(f);
	printDouble(static_cast<double>(f));
	return true;
}

bool convertFromDouble(std::string literal)
{
	char *end;
	double d;
	size_t point_index;

	if (isPseudoLiteral(literal))
		return true;
	point_index = literal.find('.');
	if (point_index == std::string::npos || point_index == literal.length() - 1) // point was not found OR the point is at the end of the string
		return false;	
	d = strtod(literal.c_str(), &end);
	if (*end)
		return false;
	printChar(d);
	printInt(d);
	printFloat(static_cast<float>(d));
	printDouble(d);
	return (true);
}

bool convertFromInt(std::string literal)
{
	int i;
	std::istringstream ss(literal);
	if (literal.find_first_not_of("-0123456789") != std::string::npos)
		return false;
	if (!(ss >> i))
		return (false);
	printChar(i);
	std::cout << "int: " << i << std::endl;
	printFloat(static_cast<float>(i));
	printDouble(static_cast<double>(i));
	return true;
}

bool convertFromChar(std::string literal)
{
	char	c;
	if (literal.length() != 1)
		return false;
	c = literal[0];
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
	return true;
}

void ScalarConverter::convert(std::string literal)
{
	if (convertFromFloat(literal))
		return ;
	if (convertFromDouble(literal))
		return ;
	if (convertFromInt(literal))
		return ;
	if (convertFromChar(literal))
		return ;
	std::cout << "Invalid input" << std::endl;
}