/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 00:16:17 by mfirdous          #+#    #+#             */
/*   Updated: 2023/07/04 00:16:17 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

Base* generate(void)
{
	srand(time(0));
	int r = rand() % 3;
	if (r == 0)
	{
		std::cout << "A created" << std::endl;
		return new A();
	}
	else if (r == 1)
	{
		std::cout << "B created" << std::endl;
		return new B();
	}
	std::cout << "C created" << std::endl;
	return new C();
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Pointer actual type is A" << std::endl; 
	else if (dynamic_cast<B*>(p))
		std::cout << "Pointer actual type is B" << std::endl; 
	else if (dynamic_cast<C*>(p))
		std::cout << "Pointer actual type is C" << std::endl; 
}

void identify(Base& p)
{
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "Reference actual type is A" << std::endl; 
	} catch (const std::exception& e) {}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "Reference actual type is B" << std::endl; 
	} catch (const std::exception& e) {}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "Reference actual type is C" << std::endl; 
	} catch (const std::exception& e) {}
}
