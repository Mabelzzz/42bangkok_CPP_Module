#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

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
		Fixed(Fixed const& copy);
		Fixed(const int nbr);
		Fixed(const float nbr);
		~Fixed();


		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed& operator=(Fixed const &rhs);
		Fixed operator+(Fixed const &rhs);
		Fixed operator-(Fixed const &rhs);
		Fixed operator*(Fixed const &rhs);
		Fixed operator/(Fixed const &rhs);

		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);


		bool operator>(Fixed const &rhs);
		bool operator<(Fixed const &rhs);
		bool operator>=(Fixed const &rhs);
		bool operator<=(Fixed const &rhs);
		bool operator==(Fixed const &rhs);
		bool operator!=(Fixed const &rhs);

		static Fixed& min(Fixed &a, Fixed &b );
		static Fixed const& min(Fixed const &a, Fixed const &b);
		static Fixed& max(Fixed &a, Fixed &b );
		static Fixed const& max(Fixed const &a, Fixed const &b);
};

std::ostream & operator<<(std::ostream &o, Fixed const &rhs);

#endif
