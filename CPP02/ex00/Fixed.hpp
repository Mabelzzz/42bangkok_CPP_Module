#ifndef FIXED_HPP
# define FIXED_HPP

#pragma once
# include <iostream>
# include <string>

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define CYAN		"\033[0;36m"
# define GRAY		"\033[0;37m"
# define LRED		"\033[0;91m"
# define BOLD		"\033[1m"
# define RESET		"\033[0m"

class Fixed {
	private:
		int _fpNum;
		static const int bits = 8;

	public:
		Fixed();
		Fixed(const Fixed &copy);
		~Fixed();


		int getRawBits( void ) const;
		void setRawBits( int const raw );
		Fixed& operator=(Fixed const& rhs);
};

#endif
