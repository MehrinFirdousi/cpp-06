/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfirdous <mfirdous@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 23:13:59 by mfirdous          #+#    #+#             */
/*   Updated: 2023/07/03 23:13:59 by mfirdous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <stdint.h>
# include <iostream>

struct Data
{
	int		i;
	char	c;
};

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& serializer);
		Serializer& operator=(const Serializer& serializer);
		~Serializer();
	
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};
#endif