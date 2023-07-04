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

#include "Serializer.hpp"

int main()
{
	Data d = {5, 'c'};
	Data *ptr;
	uintptr_t raw;

	raw = Serializer::serialize(&d);
	ptr = Serializer::deserialize(raw);
	std::cout << "original ptr = " << &d << std::endl;
	std::cout << "serialized = " << raw << std::endl;
	std::cout << "deserialized = " << ptr << std::endl;

	return (0);
}