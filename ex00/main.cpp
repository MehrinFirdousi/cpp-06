/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 15:56:03 by mfirdous          #+#    #+#             */
/*   Updated: 2023/06/22 16:47:29 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
	return (0);
}