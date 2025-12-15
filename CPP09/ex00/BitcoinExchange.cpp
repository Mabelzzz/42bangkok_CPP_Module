#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	loadDatabase("data.csv");
	std::cout << BLUE << "[Default Constructor] BitcoinExchange created." << RESET << std::endl;
}
BitcoinExchange::BitcoinExchange(const std::string& dbFilename)
{
    loadDatabase(dbFilename);
	std::cout << BLUE << "[Parameterized Constructor] BitcoinExchange created with DB: " << dbFilename << RESET << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	this->_exchangeRates = copy._exchangeRates;
	std::cout << "[Copy Constructor] Copied BitcoinExchange" << std::endl;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		_exchangeRates = other._exchangeRates;
	}
	std::cout << "[Assignment Constructor] Assigning BitcoinExchange." << std::endl;
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{
	std::cout << MAGENTA << "[Destructor] BitcoinExchange destroyed." << RESET << std::endl;
}

void BitcoinExchange::loadDatabase(const std::string& dbFilename)
{
    std::ifstream dbFile(dbFilename.c_str());

    if (!dbFile.is_open()) {
        std::cerr << "Error: could not open database file => " << dbFilename << std::endl;
        exit(1);
    }

    std::string line;
    std::getline(dbFile, line);

    while (std::getline(dbFile, line)) {
		size_t commaPos = line.find(',');
		if (commaPos == std::string::npos) {
			continue;
		}

		std::string dateStr = trim(line.substr(0, commaPos));
		std::string rateStr = trim(line.substr(commaPos + 1));

		if (!isValidDate(dateStr)) {
            std::cerr << "Warning: Skipping invalid date in DB: " << dateStr << std::endl;
            continue;
        }

		float rateValue = 0.0f;
		std::stringstream ss(rateStr);

		if (!(ss >> rateValue) || rateValue < 0) {
			continue;
		}
		_exchangeRates[dateStr] = rateValue;
    }
    dbFile.close();
}

float BitcoinExchange::getExchangeRate(const std::string& date)
{
    std::map<std::string, float>::iterator it = _exchangeRates.lower_bound(date);

    if (it == _exchangeRates.begin() && it->first != date) {
        std::cerr << "Error: date is too early => " << date << std::endl;
        return -1.0f;
    }

    if (it == _exchangeRates.end() || it->first != date) {
        --it;
    }

    return it->second;
}

void BitcoinExchange::processInputFile(const std::string& filename)
{
	std::ifstream inputFile(filename.c_str());
	if (!inputFile.is_open()) {
		std::cerr << "Error: could not open input file => " << filename << std::endl;
		return;
	}
	std::string line;
	std::getline(inputFile, line);

	while (std::getline(inputFile, line)) {
		size_t pipePos = line.find('|');
		if (pipePos == std::string::npos) {
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::string dateStr = trim(line.substr(0, pipePos));
		std::string valueStr = trim(line.substr(pipePos + 1));

		if (!isValidDate(dateStr)) {
			std::cerr << "Error: bad input => " << dateStr << std::endl;
			continue;
		}
		float amount = isValidValue(valueStr);
		if (amount < 0) {
			continue;
		}

		float rate = getExchangeRate(dateStr);

		if (rate >= 0) {
			float result = amount * rate;
			std::cout << dateStr << " => " << amount << " = " << result << std::endl;
		}
	}
}


bool BitcoinExchange::isValidDate(const std::string& date) {
	if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
		return false;
    }

    std::string yearStr = date.substr(0, 4);
    std::string monthStr = date.substr(5, 2);
    std::string dayStr = date.substr(8, 2);

    if (!isAllDigits(yearStr) || !isAllDigits(monthStr) || !isAllDigits(dayStr)) {
		return false;
    }

    int year, month, day;
    std::stringstream ys(yearStr), ms(monthStr), ds(dayStr);

    if (!(ys >> year) || !(ms >> month) || !(ds >> day)) {
		return false;
    }

    if (month < 1 || month > 12) {
		return false;
    }
    if (day < 1 || day > 31) {
		return false;
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
		return false;
    }

    if (month == 2) {
		if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) { // Leap year check
            if (day > 29) return false;
        } else {
			if (day > 28) return false;
        }
    }

    return true;
}

float BitcoinExchange::isValidValue(const std::string& valueStr) {
	float amount = 0.0f;
    std::stringstream ss(valueStr);

    if (!(ss >> amount)) {
		std::cerr << "Error: bad input format in value string." << std::endl;
        return -1.0f;
    }

	char remaining;
	if (ss >> remaining)
	{
		std::cerr << "Error: bad input format in value string." << std::endl;
		return -1.0f;
	}

    if (amount > 1000) {
		std::cerr << "Error: too large a number." << std::endl;
        return -1.0f;
    }

    if (amount < 0) {
		std::cerr << "Error: not a positive number." << std::endl;
        return -1.0f;
    }

    return amount;
}

bool isAllDigits(const std::string& str)
{
	for (size_t i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i])) {
			return false;
		}
	}
	return true;
}

std::string trim(const std::string& str)
{
    const std::string WHITESPACE = " \t\n\r";

    size_t first = str.find_first_not_of(WHITESPACE);

    if (std::string::npos == first) {
        return "";
    }

    size_t last = str.find_last_not_of(WHITESPACE);

    return str.substr(first, (last - first + 1));
}
