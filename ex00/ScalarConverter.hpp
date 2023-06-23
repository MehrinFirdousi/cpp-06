/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 18:48:12 by mfirdous          #+#    #+#             */
/*   Updated: 2023/06/22 16:32:04 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <sstream>
# include <string>
# include <cstdlib>

class ScalarConverter
{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& converter);
		ScalarConverter& operator=(const ScalarConverter& converter);
		~ScalarConverter();
		static void convert(std::string literal);
};

#endif
