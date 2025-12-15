#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# define RED		"\033[0;31m"
# define GREEN		"\033[0;32m"
# define YELLOW		"\033[0;33m"
# define BLUE		"\033[0;34m"
# define MAGENTA	"\033[0;35m"
# define GRAY		"\033[0;90m"
# define RESET		"\033[0m"

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
class BitcoinExchange
{
	private:
		std::map<std::string, float> _exchangeRates;

		void loadDatabase(const std::string& dbFilename);
		bool isValidDate(const std::string& date);
		float isValidValue(const std::string& valueStr);
		float getExchangeRate(const std::string& date);

	public:
		BitcoinExchange();
		BitcoinExchange(const std::string& dbFilename);
		BitcoinExchange(const BitcoinExchange& copy);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		void processInputFile(const std::string& filename);
};

bool isAllDigits(const std::string& str);
std::string trim(const std::string& str);

#endif
