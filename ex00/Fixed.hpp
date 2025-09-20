/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraumain <rraumain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 16:08:23 by rraumain          #+#    #+#             */
/*   Updated: 2025/09/19 13:02:12 by rraumain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
	public:
		Fixed(void);
		Fixed(const Fixed &copy);
		Fixed &operator=(const Fixed &copy);
		~Fixed(void);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);

	private:
		int					_rawBits;
		static const int	_fractionalBits;
};

#endif